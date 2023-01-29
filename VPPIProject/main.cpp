#include <iostream>
#include <vector>
#include <Windows.h>
#include "Notes.h"
using std::cout;

int main()
{
	std::vector<INote*> notes
	{
		new NoteA(0),
		new NoteASharp(0),
		new NoteB(0),
		new NoteC(0),
		new NoteCSharp(0),
	};

	for (const auto* note : notes)
	{
		Beep(note->get_frequency(), 500);
	}

	return 0;
}