#include "Layout.h"

std::vector<std::vector<int> > Layout::getLayoutInIntArray()
{
	return LayoutDescription;
}

Layout * Layout::getNextLayout()
{
	Layout *result = Next;
	Next = nullptr;
	return result;
}

bool Layout::ChangeLayout()
{
	bool result = LayoutChangeFlag;
	LayoutChangeFlag = false;
	return result;
}

void Layout::ConfirmBuffer()
{
	buffer = nullptr;
}

void Layout::EraseLastCharacterFromBuffer()
{
	buffer->pop_back();
}

void Layout::AddCharacterToBuffer(char character)
{
	if (buffer == nullptr)
		return;

	if (character >= 'a' && character <= 'z')
		character = character - 'a' + 'A';
	
	if (character >= 'A' && character <= 'Z')
		*buffer += character;
}

Layout::Layout(sf::RenderWindow *n_window)
{
	Next = nullptr;
	LayoutChangeFlag = false;
	buffer = nullptr;
	ObjectsMaxId = 0;
	CursorType = sf::Cursor::Arrow;
	this->window = n_window;
	isButtonReleased = true;
}

std::string Layout::GetFileName()
{
	char filename[MAX_PATH];
	wchar_t filepath[MAX_PATH];

	OPENFILENAME ofn;
	ZeroMemory(&filename, sizeof(filename));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
	ofn.lpstrFilter = _T("Text Files\0*.txt\0Any File\0*.*\0");
	ofn.lpstrFile = LPWSTR(filename);
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = _T("Select a File, yo!");
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	if (GetOpenFileName((LPOPENFILENAME)&ofn))
	{
		wcscpy_s(filepath, ofn.lpstrFile);
		wchar_t *f = filepath;
		std::wstring ws(f);
		std::string str(ws.begin(), ws.end());
		
		return str;
	}
	else
	{
		// All this stuff below is to tell you exactly how you messed up above. 
		// Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
		switch (CommDlgExtendedError())
		{
		case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
		case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
		case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
		case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
		case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
		case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
		case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
		case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
		case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
		case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
		case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
		case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
		case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
		case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
		case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
		default: std::cout << "You cancelled.\n";
		}

		return "";
	}
}

int Layout::IncId()
{
	return ++ObjectsMaxId;
}

void Layout::GenerateDescription(sf::RenderWindow *window)
{
	// create LayoutDescription according to LayoutObjeccts list rects
	int n = window->getSize().x; n += 50;
	int m = window->getSize().y; m += 50;
	
	LayoutDescription.resize(n);

	for (int i = 0; i < n; i++)
	{
		LayoutDescription[i].resize(m);
		for (int j = 0; j < m; j++)
			LayoutDescription[i][j] = 0;
	}
	
	
	for (auto obj: ObjectsList)
	{
		for (int i = obj->Position.x;
			i < obj->Position.x + obj->Size.x;
			i++)

			for (int j = obj->Position.y;
				j < obj->Position.y + obj->Size.y;
				j++)

				LayoutDescription[i][j] = obj->HidenFromUser ? 0 : obj->ObjectId;
	}
}
