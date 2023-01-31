#include <iostream>
#include <memory>
#include "ConsoleDocumentEditor.h"

auto main() -> int
{
	decltype(auto) app = ConsoleDocumentEditor::get_instance();
	return app.execute();
}