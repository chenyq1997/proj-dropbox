#include <stdio.h>	//remove(1)


void ListStorage()
{
	list_aph_fdict();
}

void RetrieveFile(const char* input)
{
	//Find in dict
	filename* res = find_filename(input);
	if(res == NULL) cout << "File not found in master storage.\n" << endl;
	else
	{
		Chunk* cptr;
		cptr = res->first;
		while(cptr->next != NULL)
		{

		}		
	}	
}

void DeleteFile(const char* input)
{
	//Find in dict
	filename* res = find_filename(input);
	if(res == NULL) cout << "File not found in master storage.\n" << endl;
	else
	{
		Chunk* cptr;
		cptr = res->first;
		while(cptr != NULL)
		{
			count_down(cptr->name);
			if(find_chunkname(cptr->name)->count == 0)
			{
				if(remove(cptr->name) == 0) continue;
				else cout << "Error: chunk data removal unsuccessful."
				find_chunkname(cptr->name)->delete_from_cdict();
			}
			cptr = cptr->next;
		}
		res->delete_from_fdict();
		//free(res);
		cout << "Successfully deleted " << input << " from master storage." << endl;
	}
}