#include <iostream>
#include <memory>
#include "ConsoleDocumentEditor.h"

auto main() -> int
{
	auto app = std::make_unique<ConsoleDocumentEditor>(std::cout, std::cin);
	return app->execute();
}