#include <deque>
#include <type_traits>
#include <iostream>
#include <signal.h>

#include "ScaleValue.h"
#include "ScaleRate.h"
#include "Scale.h"

#include "Pot.h"
#include "Button.h"
#include "Display.h"
#include "CloudConnection.h"

#include "Config.h"

#define HISTORY_LENGTH 5
#define PICKUP (-200)
#define DROP (200)

static volatile bool running = true;

void sigint_handler(int s) {
	running = false;
}

int main() {
	signal(SIGINT, sigint_handler);

	std::deque<ScaleValue> prev;
	ScaleValue full(500), empty;
	ScaleRate rate;
	std::string name("");

	Scale scale;
	Display display;
	Pot go_at_percent(WARN_POT);
	Button full_button(FULL_BUTTON);
	Button empty_button(EMPTY_BUTTON);
	CloudConnection cloud;
	for (int i = 0; i < HISTORY_LENGTH; i++) {
		prev.push_front(scale.read());
	}

	int picked_up = 0;
	int settle_delay = -1;
	unsigned int i = 0;

	while (running) {
		ScaleValue current = scale.read();
		prev.pop_back();
		prev.push_front(current);
		rate = ScaleValue::get_rate(prev);

		if (rate < PICKUP) {
			picked_up = 200;
		}

		if (picked_up) {
			picked_up--;
		}


		//wait after drop for value to stabilize
		if (rate > DROP) {
			settle_delay = 10;
		}
		if (settle_delay > 0) {
			settle_delay--;
		}
		if (settle_delay == 0) {
			picked_up = false;
			settle_delay = -1;
			//then send it
			cloud.send(current);
		} else if (i % 256 == 0 && !picked_up && current > empty) { //send updates sometimes
			cloud.send(current);
			name = cloud.name();
		}

		if (full_button.pressed()) {
			full = scale.read();
			cloud.send_full(full);
			full_button.clear();
		}
		if (empty_button.pressed()) {
			empty = scale.read();
			cloud.send_empty(empty);
			empty_button.clear();
		}
		bool warn = false;
		if (!picked_up && current <
				ScaleValue::interpolate(full, empty, go_at_percent.value()) ) {
			warn = true;
		} else {
			warn = false;
		}


		display.write(full, empty, current, rate, picked_up, warn, go_at_percent.value(), name);
		scale.wait();

		i++;
	}
	std::cout << "exiting gracefully" << std::endl;
	return 0;
}
