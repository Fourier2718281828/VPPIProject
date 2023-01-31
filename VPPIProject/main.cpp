//#include <iostream>
//#include "TextHeader.h"
//#include "PlainTextDocument.h"
//using std::cout;
//using std::cin;
//using std::ostream;
//
//std::ostream& operator<< (std::ostream& o, const IHeader& h)
//{
//	static const char* const edge = "-------------------------------------------\n";
//	o << edge << h.get_title() << '\n';
//
//	auto in_t_acts = h.get_input_operations();
//	o << "Input Operations:\n";
//	for (auto i = 0u; i < in_t_acts.size(); ++i)
//	{
//		o << (i + 1) << "). " << in_t_acts[i].first << '\n';
//	}
//
//	auto procs = h.get_procedures();
//	o << "Input Operations:\n";
//	for (auto i = 0u; i < procs.size(); ++i)
//	{
//		o << (i + 1 + in_t_acts.size()) << "). " << procs[i].first << '\n';
//	}
//
//	return o << edge;
//}
//
//int main()
//{
//	IHeader* header = new TextHeader();
//	IDocument* document = new PlainTextDocument();
//	auto in_t_acts = header->get_input_operations();
//	auto procs = header->get_procedures();
//
//	while (true)
//	{
//		cout << *header;
//		int choice;
//		cin >> choice;
//		
//		if (choice - 1 < in_t_acts.size())
//		{
//			in_t_acts[choice - 1].second(*document, "fuck");
//		}
//		else
//		{
//			choice -= in_t_acts.size() + 1;
//			procs[choice].second(*document);
//		}
//	}
//
//	return 0;
//}


#include <iostream>
#include "ConsoleDocumentEditor.h"

auto main() -> int
{
	
	auto app = ConsoleDocumentEditor(std::cout, std::cin);
	return 0;
}