#include "stdafx.h"
#include "Designer.h"
#include "PictureDraft.h"
#include "IShapeFactory.h"
#include <iostream>

using namespace std;

CDesigner::CDesigner(IShapeFactory & factory)
	:m_factory(factory)
{
}

CPictureDraft CDesigner::CreateDraft(std::istream & inputData)
{
	CPictureDraft draft;
	string line;
	while (getline(inputData, line))
	{
		try
		{
			draft.AddShape(m_factory.CreateShape(line));
		}
		catch (const std::invalid_argument & ex)
		{
			std::cerr << "Error: " << ex.what() << std::endl;
		}
	}
	return draft;
}
