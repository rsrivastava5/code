// Class code for Tuesday February 18
// We want to create a class called Frame
// This frame is a rectangular grid of characters to display on the screen
// at a given location, we wil also provide a method for reading a sequence
// of frames from a file, and for displaying a sequence of frames at specific
// intervals, to achieve animation

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unistd.h>

using namespace std;

class Frame {
private:
	vector<string> rows;

	//Positions the cursor at the requested coordinates using ANSI escape codes
	//Discuss functions that can be defined inline and out of line, and what inlining does
	void move_cursor_to(size_t row, size_t col) {
		cout << "\033[" << row << ";" << col << "H" << flush;
	}

public:
	//This is the constructor. Discuss in the forums.
	//Should vec be called by copy or reference?
	Frame(vector<string> vec) : rows(vec) {}
    void show_frame_at(size_t row, size_t col);
    void clear_frame_at(size_t row, size_t col);
};

// Out of line implementations (discuss in the forums)
// TODO: make this function look the same as the clear frame function
void Frame::show_frame_at(size_t row, size_t col) {
	for (size_t i = 0; i < rows.size(); ++i)
		cout << "\033[" << (row + i) << ";" << col << "H" << rows[i] << flush;
}

void Frame::clear_frame_at(size_t row, size_t col) {
	for (size_t i = 0; i < rows.size(); ++i) {
		move_cursor_to(row + i, col);
		cout << string(rows[i].size(), ' ') << flush;
	}
}


//This function will read a sequence of frames from a file into a vector of
//frames passed by reference (Discuss why) and returns the number of read frames
//Within the file each frame is given as a series of lines beginning with a ' '
//Lines beginning with '!' end the frame
size_t read_frame_sequence_from_file(vector<Frame> &frames, const string file_name) {
	ifstream ifs(file_name);

	if (!ifs) {
		cerr << "Could not read from " << file_name << endl;
		exit(1);
	}

	vector<string> page_content;
	string buffer;
	while (getline(ifs, buffer))
	{
		if (buffer[0] == ' ') {
			page_content.push_back(buffer);
		}
		if (buffer[0] == '!') {
			Frame frame(page_content);
			page_content.clear();
			frames.push_back(frame);
		}
	}

	return frames.size();
}

// This function should show each frame in the vector of frames with the left corner at
// row, col and then sleep for delay_ms and then clear the current frame and
// show the next frame until there are no more frames left
// Discuss how an object's methods are being called below
// Objects are stored in our vector called frames, which is an array of many
// Frame objects (data items of the class that we just defined)
void show_frame_sequence_at(vector<Frame> &frames, size_t row, size_t col, size_t delay_ms) {
	for (size_t i = 0; i < frames.size(); i++) {
		frames[i].show_frame_at(row, col);
		usleep(delay_ms * 1000); // Convert from ms to micro seconds for usleep
		frames[i].clear_frame_at(row, col);
	}
}


int main(int argc, char **argv)
{
	vector<Frame> frames;
	const string INPUT_FILE = "frames.txt";

	cout << "Reading frames from " << INPUT_FILE << "..." << endl;
	size_t num_frames = read_frame_sequence_from_file(frames, INPUT_FILE);
	cout << "Read " << num_frames << " frames from " << INPUT_FILE << endl;

	//Allow a few seconds before the animation clears the text
	sleep(3);

	if(num_frames == 0) {
		cout << "No frames to display. Exiting." << endl;
		return 0;
	}

	//Show each frame in the vector with an interval of 500 MS between them
	show_frame_sequence_at(frames, 5, 5, 500);

	return 0;
}