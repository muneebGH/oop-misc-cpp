#include"IEditor.h"
IEditor::IEditor(CString fn) :filename(fn)
{
	currentLine = 0;
	noOfLines = 0;
	capacity = 100;
	data = new CString *[capacity];
	for (int i = 0; i < capacity; i = i + 1)
	{
		data[i] = 0;
	}
}

void IEditor::start()
{
	cout << "<<<<<<<<<<<<<<<<<"; filename.display(); cout << "<<<<<<<<<<<<<<<<<<<" << endl;
	bool IStatus = false;
	bool status = true;
	while (status)
	{

		if (currentLine == noOfLines)
		{
			IStatus = false;
		}

		cout << currentLine + 1 << "<";
		CString input;
		input.input();
		char ch = input.at(0);
		if (ch =='A')
		{
			if (IStatus == true)
			{
				currentLine = currentLine + 1;
			}
			
			forA(input);
		}
		else if (ch == 'L')
		{
			forL(input);
			currentLine = noOfLines;
		}
		else if (ch == 'D')
		{
			forD(input);
		}
		else if (ch == 'I')
		{
			int index =input.find(" ");
			if (index > 0)
			{
				input.remove(0, 2);
				int line = input.toInteger();
				if (line <= noOfLines)
				{
					currentLine = line - 1;
				}
			}
			else
			{
				currentLine = currentLine - 1;
			}
			IStatus = true;
		}
		else if (ch == 'E')
		{
			status = false;
		}
		else
		{

			if (IStatus == false && noOfLines <= capacity)
			{
				noOfLines = noOfLines + 1;
			}
			if (currentLine <= noOfLines)
			{

				data[currentLine] = new CString;
				*(data[currentLine]) = input;
				currentLine = currentLine + 1;
			}
		}
	};
}

void IEditor::forA(CString input)
{
	CString temp = input;
	int index = temp.find(" ");
	if (index == -1)
	{
		cout << currentLine << "<";
		CString append;
		append.input();
		data[currentLine-1]->concatEqual(append);
	}
	else
	{
		temp.remove(0, 2);
		int line = temp.toInteger();
		cout << line << "<";
		CString append;
		append.input();
		data[line - 1]->concatEqual(append);

	}
}


void IEditor::forL(CString input)
{
	char ch='\0';
	if (input.getLength() != 1)
	{
		ch = 'N';
	}
	if (ch == '\0')
	{
	    for (int i = 0; i < noOfLines; i = i + 1)
		{
			cout << i + 1 << "<"; data[i]->display();cout << endl;
		}
	}

	if (ch != '\0' && (input.at(2) >= 48 && input.at(2) <= 58))
	{
		CString temp=input;
		temp.remove(0, 2);
		int onIndex = temp.find(" ");
		if (onIndex == -1)
		{
			int lineNo = temp.toInteger();
			if (lineNo <= noOfLines)
			{
				cout << lineNo << "<"; data[lineNo-1]->display(); cout << endl;
			}
		}
		else if (onIndex >0)
		{
			CString temp2 = temp;
			 temp.remove(onIndex, (temp.getLength() - onIndex));
			 int start = temp.toInteger();
			 temp2.remove(0, onIndex + 1);
			 int end = temp2.toInteger();
			 for (int i = start; i <= end; i = i + 1)
			 {
				 cout << i << "<";
				 data[i - 1]->display();
				 cout << endl;
			 }
		}
	}
}



void IEditor::forD(CString input)
{

	char ch='\0';
	if (input.getLength() != 1)
	{
		ch = 'N';
	}
	if (ch == '\0')
	{
		data[currentLine]->~CString();
		noOfLines = noOfLines - 1;
		currentLine = currentLine - 1;
	}

	if (ch != '\0' && (input.at(2) >= 48 && input.at(2) <= 58))
	{
		CString temp = input;
		temp.remove(0, 2);
		int onIndex = temp.find(" ");
		if (onIndex == -1)
		{
			int lineNo = temp.toInteger();
			data[lineNo - 1]->~CString();
			for (int i = lineNo; i < noOfLines; i = i + 1)
			{
				data[i - 1] = data[i];
			}
			noOfLines = noOfLines - 1;
			currentLine = currentLine - 1;

		}
		else if (onIndex > 0)
		{
			CString temp2 = temp;
			temp.remove(onIndex, (temp.getLength() - onIndex));
			int start = temp.toInteger();
			temp2.remove(0, onIndex + 1);
			int end = temp2.toInteger();
			for (int i = start; i <=end; i = i + 1)
			{
				data[i - 1]->~CString();
				
			}
			int end2 = end;
			for (int i = 0;i < (noOfLines - end); i = i + 1)
			{
				data[start - 1] = data[end2];
				end2 = end2 + 1;
				start=start + 1;
			}
			currentLine = start;
			noOfLines = end - start;
		}
	}
}

