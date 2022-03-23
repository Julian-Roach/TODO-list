/**************************************************************************************************
TODO-list - A TODO list program. Made with DOSELTA.

The Description: TODO-list is just a TODO list project. It stores your TODO tasks, and you can mark
them as DONE as well, if you wish.

Reason: I wanted to remember all the things I planned to do in the future. I had had so many ideas,
that I had them saved in random places, like: my phone, my whiteboard, my PC, notebooks and some
others. I could not keep up with them, so I decided to create this.

This project isn't meant to be used by anyone, but if you like it, and you would like to "upgrade"
it a little, feel free to pull request your changes!
**************************************************************************************************/

#include <iostream>
#include <DOSELTA.h>

#include "macrosTODO.h"
#include "function_declarations.h"

void additionalInformation()
{
	LOG(SPLITTING_LINE);
	LOG("NOTE: all of the commands below except \"resume\" affect the TODO list.");
	LOG(SPLITTING_LINE);
}

int main()
{
	bool running = true;

	DOS::Prepare();
	DOS::CommandManager commands;
	DOS::InputHandler   commander(&commands);

	// Add arguments.
	std::string arg1, arg2;
	commander.addArgument(&arg1);
	commander.addArgument(&arg2);

	// Create the DONE storage.
	DOS::BookFile DONEs("DONEs");
	DONEs.read();

	// Create the TODO storage.
	DOS::BookFile TODOs("TODOs");
	TODOs.read();

	// All commands.
	DOS::Command coms("coms", "Use to display all the commands you can use.", [&commands] { commands.displayCommands(); });


	DOS::Command add("add", "Use to add some task.", [&TODOs, &arg1] { TODOs.addPage(arg1); });
	DOS::Command edit("edit", "Use to edit some task. (index, content)", [&TODOs, &arg1, &arg2] { unsigned int page = std::stoi(arg1) - 1; if (!DOS::indexCheck(page, TODOs.size(), USERMISTAKE_INDEXBAD)) { return; } TODOs.setPage(page, arg2); });
	DOS::Command remove("remove", "Use to remove a task from the list.", [&TODOs, &arg1] { unsigned int page = std::stoi(arg1) - 1; if (!DOS::indexCheck(page, TODOs.size(), USERMISTAKE_INDEXBAD)) { return; } TODOs.removePage(page); });
	
	DOS::Command done("done", "Use to mark a task as done", [&TODOs, &DONEs, &arg1] { moveToBook(TODOs, DONEs, stoi(arg1) - 1); });
	DOS::Command resume("resume", "Use to mark a task as undone", [&TODOs, &DONEs, &arg1] { moveToBook(DONEs, TODOs, stoi(arg1) - 1); });

	DOS::Command save("save", "Use to save the data.", [&TODOs, &DONEs] { TODOs.write(); DONEs.write(); });
	DOS::Command close("close", "Use to save the data and close.", [&TODOs, &DONEs, &running] { TODOs.write(); DONEs.write(); running = false; });

	commands.add(coms);
	
	commands.add(add);
	commands.add(edit);
	commands.add(remove);

	commands.add(done);
	commands.add(resume);

	commands.add(save);
	commands.add(close);

	additionalInformation();
	coms.function();

	while (running)
	{
		LOG(SPLITTING_LINE);
		listBooksParallel(TODOs, DONEs);

		commander.getInput();

		DOS::ClearScreen();

		commander.handleInput();

	}

	return 0;
}