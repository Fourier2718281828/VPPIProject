#include <iostream>
#include <vector>
#include "Notes.h"
#include <Windows.h>
using std::cout;

int main()
{
	std::vector<INote*> notes
	{
		new NoteA(1),
		new NoteASharp(1),
		new NoteB(1),
		new NoteC(1),
		new NoteCSharp(1),
	};

	for (const auto* note : notes)
	{
		Beep(note->get_frequency(), 500);
	}

	return 0;
}