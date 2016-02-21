#include <deque>
#include <type_traits>
#include <signal.h>

#include "ScaleValue.h"
#include "ScaleRate.h"
#include "Scale.h"

#include "Pot.h"
#include "Button.h"
#include "Display.h"

#include "CloudConnection.h"

#include "Config.h"

#define HISTORY_LENGTH 50
#define PICKUP (100)
#define DROP (-100)

static volatile bool running = 1;

void sigint_handler(int s) {
	running = 0;
}

int main() {
	signal(SIGINT, sigint_handler);

	std::deque<ScaleValue> prev;
	ScaleValue full, empty;
	ScaleRate rate;

	Scale scale;
	Display display;
	Pot go_at_percent(WARN_POT);
	Button full_button(FULL_BUTTON);
	Button empty_button(EMPTY_BUTTON);
	CloudConnection cloud;
	for (int i = 0; i < HISTORY_LENGTH; i++) {
		prev.push_front(scale.read());
	}

	while (running) {
		ScaleValue current = scale.read();
		prev.pop_back();
		prev.push_front(current);
		rate = ScaleValue::get_rate(prev);
		bool picked_up = false;
		if (rate < PICKUP) {
			picked_up = true;
			//pickup
		}
		int settle_delay = -1;
		if (rate > DROP) {
			//drop
			settle_delay = 50;
		}
		if (settle_delay > 0) {
			settle_delay--;
		}
		if (settle_delay == 0) {
			picked_up = false;
			settle_delay = -1;
			cloud.send(current);
			//send drop to cloud
		}
		//main loop
		if (full_button.pressed()) {
			full = scale.read();
		}
		if (empty_button.pressed()) {
			empty = scale.read();
		}
		bool warn = false;
		if (!picked_up && current <
				ScaleValue::interpolate(full, empty, go_at_percent.value()) ) {
			warn = true;
		} else {
			warn = false;
		}

		display.write(full, empty, current, rate, picked_up, warn, go_at_percent.value());
		scale.wait();
	}

	return 0;
}
