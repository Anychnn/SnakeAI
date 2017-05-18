#include"KeyEvent.h"
void KeyEvent::KeyDown(unsigned char key) {
	if (key == 'w') {
		snk->direction = snk->up;
	}
	else if (key == 'd') {
		snk->direction = snk->right;
	}
	else if (key == 's') {
		snk->direction = snk->down;
	}
	else if (key == 'a') {
		snk->direction = snk->left;
	}
}

void KeyEvent::SpecialKeyDown(unsigned int key) {
	if (key == 101) {
		if (snk->direction == Snake::down) {
			return;
		}
		snk->direction = snk->up;
	}
	else if (key == 102) {
		if (snk->direction == Snake::left) {
			return;
		}
		snk->direction = snk->right;
	}
	else if (key == 103) {
		if (snk->direction == Snake::up) {
			return;
		}
		snk->direction = snk->down;
	}
	else if (key ==100) {
		if (snk->direction == Snake::right) {
			return;
		}
		snk->direction = snk->left;
	}
}