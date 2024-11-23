#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <cstdio>
#include <sys/wait.h>
#include <stdlib.h>

#define WIN_NUM 300

void B_Call(Fl_Widget* widget, void* data) {
	printf("Hello World\n");
	fflush(stdout);
}


void new_win(Fl_Widget* widget, void* data) {
	int x = 0;
	int y = 0;
	int winnum = 0;
	Fl_Window** n_win = new Fl_Window*[WIN_NUM];
	Fl_Box** n_box = new Fl_Box*[WIN_NUM];
	for (int i = 1; i < WIN_NUM; i++) {
		n_win[i] = new Fl_Window(300, 200);
		n_box[i] = new Fl_Box(250, 150, -200, -100, "Task failed successfully");
		n_win[i]->position(x, y);
		n_box[i]->box(FL_NO_BOX);
		n_box[i]->labelfont();
		n_box[i]->labelsize(25);
		n_win[i]->end();
		n_win[i]->show();
		printf("%d: %d, %d\n",i ,x, y);
		fflush(stdout);
		if (y >= (Fl::h() - 200)) {
			y = 0;
			x += 50;
		}
		if (x >= (Fl::w() - 300)) {
			break;
		}
		x += 10;
		y += 30;
		winnum++;
	}
	
	
	delete[] n_win;
	delete[] n_box;

}

int main(int argc, char **argv) {
	Fl_Window *win = new Fl_Window(340, 300);
	Fl_Box *box = new Fl_Box(20, 100, 300, 100, "Hello World");
	Fl_Button* button = new Fl_Button(100, 30, 100, 40, "test");
	Fl_Button* win_B = new Fl_Button(200, 30, 100, 40, "window");
	box->box(FL_DOWN_BOX);
	box->labelfont();
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);
	button->callback(B_Call);
	win_B->callback(new_win);
	win->end();
	win->show(argc, argv);
	return Fl::run();
}
