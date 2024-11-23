LIBS = -lfltk -lwayland-client -lwayland-egl

build:
	g++  ./src/main.cpp $(LIBS) -o app
