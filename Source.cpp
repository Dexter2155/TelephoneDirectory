#include <iostream>
#include <string.h>
#include<conio.h>
#include<stdio.h>
#include <cstdlib>
using namespace std;

struct TreeNode
{
	int id;
	int contactno;
	char name[20];
	char address[50];

	TreeNode *left;
	TreeNode *right;
};


class td : public TreeNode//class for functions or operation
{

private:
	TreeNode* root;
	int totalperson;

public:
	td();
	bool respond();
	int showmenu();
	bool insertobject();
	bool addtoarray(int, char*, char*, int);
	bool listdirectory();
	bool searchTreeNode();
	bool updateTreeNode();
	bool deleteTreeNode();

	bool insertnode(TreeNode *newNode);
	bool insertdata(int, char*, char*, int);
	bool inputnode();

	void PrintOne(TreeNode *T);
	bool PrintTree();
	void PrintAll(TreeNode *T);
	bool Searchnode(int id);
	bool Search();

	bool Deletenode(int id);
	bool Deletee();

	bool Updatenode(int id);
	bool Update();


};



td::td() // defult constructor
{
	root = NULL;
	totalperson = 0;
}
bool td::insertnode(TreeNode *newNode)
{
	TreeNode *temp;
	TreeNode *back;

	temp = root;
	back = NULL;

	while (temp != NULL) // Loop till temp falls out of the tree 
	{
		back = temp;
		if (newNode->id < temp->id)
			temp = temp->left;
		else
			temp = temp->right;
	}

	// Now attach the new node to the node that back points to 
	if (back == NULL) // Attach as root node in a new tree 
		root = newNode;
	else
	{
		if (newNode->id < back->id)
			back->left = newNode;
		else
			back->right = newNode;
	}
	return(true);
}


bool td::insertdata(int id, char *name, char *address, int contactno)
{
	TreeNode *newNode;

	// Create the new node and copy data into it
	newNode = new TreeNode();
	newNode->id = id;
	strcpy_s(newNode->name, name);
	strcpy_s(newNode->address, address);
	newNode->contactno = contactno;
	newNode->left = newNode->right = NULL;

	// Call other Insert() to do the actual insertion
	return (insertnode(newNode));
}

bool td::inputnode(){
	cout << "*************************************" << endl;
	cout << "  Telephone Directory: Insert Menu" << endl;
	cout << "*************************************" << endl;



	int id;
	char* name = new char[50];
	char address[50];
	int contactno;
	int option, n;

	//takes the value of the record

	cout << "Enter Id:";
	cin >> id;

	fflush(stdin);
	cout << "Enter Name:";
	cin >> name;
	//cin.getline(name, 40);
	//cin.getline(cin, name);
	fflush(stdin);
	cout << "Enter Contact No:";
	cin >> contactno;
	fflush(stdin);
	cout << "Enter Address:";
	cin.getline(address, 50);
	cout << endl;

	int optionofsave;

	cout << "Press 1 to save ,0 to not save" << endl;
	cin >> optionofsave;


	if (optionofsave == 1) // if want to save then send values to the addtoarray function
	{

		insertdata(id, name, address, contactno);
		cout << "Record saved successfully." << endl;
	}
	else if (optionofsave == 0)
	{
		return true;
	}
	char insertagain;
	cout << "Want to insert another record? [y/n]" << endl;
	cin >> insertagain;


	if (insertagain == 'y')
	{
		return false;
	}
	else if (insertagain == 'n')
	{
		return true;
	}
}


bool td::respond() // functon to get the responce of the user for particuler functions
{
	int option;
	option = showmenu();
	bool result = true;

	switch (option)
	{
	case 1:
		do{
			system("CLS"); // clear screan
			result = inputnode(); //calls the insert function

		} while (result == false); //if false comes the do whiles start again and if true loop ends
		break;
	case 2:
		do{
			system("CLS");

			result = PrintTree();

		} while (result == false);
		break;
	case 3:
		do{
			system("CLS");

			result = Search();

		} while (result == false);
		break;
	case 4:
		do{
			system("CLS");

			result = Update();

		} while (result == false);
		break;


	case 5:
		do{
			system("CLS");

			result = Deletee();

		} while (result == false);
		break;

	case 6:
		return false;




	}
	if (result = true)
	{
		return true;
	}



}
int td::showmenu() //// shows menu of the progrram
{
	system("CLS");
	int option;

	cout << "*************************************" << endl;
	cout << "   Telephone Directory: Main Menu" << endl;
	cout << "*************************************" << endl;

	cout << "\n\n1. Insert a new record\n2. List Records\n3. Search a Record\n";
	cout << "4. Update a record(using name or ID)\n5. Delete a Record\n6. Exit program";

	cout << "\n\nSelect Option [1, 2, 3, 4, 5, 6]:";
	cin >> option;

	return option;

}


bool td::insertobject(){

	cout << "*************************************" << endl;
	cout << "Telephone Directory: Insert Menu" << endl;
	cout << "*************************************" << endl;


	int id;
	char* name = new char[50];
	char address[50];
	int contactno;
	int option, n;

	//takes the value of the TreeNode

	cout << "Enter Id:";
	cin >> id;

	//fflush(stdin);
	cout << "Enter Name:";
	cin.getline(name, 20);

	fflush(stdin);
	cout << "Enter Contact No:";
	cin >> contactno;
	fflush(stdin);
	cout << "Enter Address:";
	cin.getline(address, 50);
	cout << endl;

	int optionofsave;

	cout << "Press 1 to save ,0 to not save" << endl;
	cin >> optionofsave;


	if (optionofsave == 1) // if want to save then send values to the addtoarray function
	{
		insertdata(id, name, address, contactno);
		cout << "TreeNode saved successfully." << endl;
	}
	else if (optionofsave == 0)
	{
		return true;
	}
	char insertagain;
	cout << "Want to insert another TreeNode? [y/n]" << endl;
	cin >> insertagain;


	if (insertagain == 'y')
	{
		return false;
	}
	else if (insertagain == 'n')
	{
		return true;
	}
}


//--------------------------------------------
// Function: PrintOne()                                      
// Purpose: Print data in one node of a tree.
// Preconditions: None
// Returns: void                               
//--------------------------------------------
void td::PrintOne(TreeNode *T)
{
	cout << T->id << "\t\t" << T->name << "\t\t" << T->address << "\t\t" << T->contactno << "\t\t\n";

}

//--------------------------------------------
// Function: PrintAll()                                     
// Purpose: Print the tree using a recursive
//        traversal 
// Preconditions: None
// Returns: void                               
//--------------------------------------------
void td::PrintAll(TreeNode *T)
{
	if (T != NULL)
	{
		PrintAll(T->left);
		PrintOne(T);
		PrintAll(T->right);
	}
}

//--------------------------------------------
// Function: PrintTree()                                     
// Purpose: Print the tree using a recursive
//        traversal.  This gives the user access
//        to PrintAll() without giving access to
//        the root of the tree.
// Preconditions: None
// Returns: void                               
//--------------------------------------------
bool td::PrintTree()
{
	PrintAll(root);

	cout << "\nPress 'm' to go to Main menu:" << endl;
	char m;
	cin >> m;
	if (m == 'm')
	{
		return true;
	}
}

bool td::Searchnode(int id)
{
	TreeNode *curr = root;
	while (curr != NULL)
	{
		if (curr->id == id)
			break;

		if (curr->id<id)
			curr = curr->right;
		else
			curr = curr->left;

	}
	if (curr == NULL){

		cout << "\n ID does not found:\n";
		return true;
	}
	cout << "\n\Found the record:\n";
	PrintOne(curr);

	return true;



}
bool td::Search()
{
	cout << "*************************************" << endl;
	cout << "  Telephone Directory: Search Menu" << endl;
	cout << "*************************************" << endl;


	int idtofind;
	cout << "\nEnter id to be find: ";  //takes id to be searched
	cin >> idtofind;
	if (Searchnode(idtofind)){

	}
	else {
	}

	char searchagain;
	cout << "\nDo you want to search another record? [y/n]";    //search again
	cin >> searchagain;
	if (searchagain == 'y')
		return false;
	else if (searchagain == 'n')
		return true;

}


bool td::Deletenode(int id)
{
	TreeNode *back;
	TreeNode *temp;
	TreeNode *delParent;    // Parent of node to delete
	TreeNode *delNode;      // Node to delete

	temp = root;
	back = NULL;

	// Find the node to delete 
	while ((temp != NULL) && (id != temp->id))
	{
		back = temp;
		if (id < temp->id)
			temp = temp->left;
		else
			temp = temp->right;
	}

	if (temp == NULL) // Didn't find the one to delete 
	{
		cout << "ID not found. Nothing deleted.\n";
		return false;
	}
	else
	{
		if (temp == root) // Deleting the root 
		{
			delNode = root;
			delParent = NULL;
		}
		else
		{
			delNode = temp;
			delParent = back;
		}
	}

	// Case 1: Deleting node with no children or one child 
	if (delNode->right == NULL)
	{
		if (delParent == NULL)    // If deleting the root    
		{
			root = delNode->left;
			delete delNode;
			return true;
		}
		else
		{
			if (delParent->left == delNode)
				delParent->left = delNode->left;
			else
				delParent->right = delNode->left;
			delete delNode;
			return true;
		}
	}
	else // There is at least one child 
	{
		if (delNode->left == NULL)    // Only 1 child and it is on the right
		{
			if (delParent == NULL)    // If deleting the root    
			{
				root = delNode->right;
				delete delNode;
				return true;
			}
			else
			{
				if (delParent->left == delNode)
					delParent->left = delNode->right;
				else
					delParent->right = delNode->right;
				delete delNode;
				return true;
			}
		}
		else // Case 2: Deleting node with two children 
		{
			// Find the replacement value.  Locate the node  
			// containing the largest value smaller than the 
			// key of the node being deleted.                
			temp = delNode->left;
			back = delNode;
			while (temp->right != NULL)
			{
				back = temp;
				temp = temp->right;
			}
			// Copy the replacement values into the node to be deleted 
			delNode->id = temp->id;

			delNode->contactno = temp->contactno;

			strcpy_s(delNode->name, temp->name);

			strcpy_s(delNode->address, temp->address);




			// Remove the replacement node from the tree 
			if (back == delNode)
				back->left = temp->left;
			else
				back->right = temp->left;
			delete temp;
			return true;
		}
	}


}
bool td::Deletee(){

	cout << "*************************************" << endl;
	cout << "  Telephone Directory: Delete Menu   " << endl;
	cout << "*************************************" << endl;


	int idtofind;

	cout << "\nEnter id to delete the record: ";  //takes id to be searched
	cin >> idtofind;

	if (Deletenode(idtofind)){
		cout << "\n Record deleted successfully";
	}
	else {
		cout << "\n Record does not find";
	}

	char deleteagain;

	cout << "\nDo you want to delete another record? [y/n]";    //search again
	cin >> deleteagain;
	if (deleteagain == 'y')
		return false;
	else if (deleteagain == 'n')
		return true;



}

bool td::Updatenode(int id)
{
	TreeNode *curr = root;
	while (curr != NULL)
	{
		if (curr->id == id)
			break;

		if (curr->id<id)
			curr = curr->right;
		else
			curr = curr->left;

	}
	if (curr == NULL){

		cout << "\n ID does not found:\n";
		return false;
	}


	cout << "\n\nFound the record:\n\n";
	cout << "Enter the values to update the this record:\n\n";


	int idd;
	char* name = new char[50];
	char address[50];
	int contactno;
	int option, n;

	//takes the value of the TreeNode

	cout << "Enter Id:";
	cin >> idd;

	fflush(stdin);
	cout << "Enter Name:";
	cin.getline(name, 20);

	fflush(stdin);
	cout << "Enter Contact No:";
	cin >> contactno;
	fflush(stdin);
	cout << "Enter Address:";
	cin.getline(address, 50);
	cout << endl;


	curr->id = idd;

	curr->contactno = contactno;

	strcpy_s(curr->name, name);

	strcpy_s(curr->address, address);



	return true;



}
bool td::Update(){

	cout << "*************************************" << endl;
	cout << "  Telephone Directory: Update Menu   " << endl;
	cout << "*************************************" << endl;


	int idtofind;

	cout << "\nEnter id to delete the record: ";  //takes id to be searched
	cin >> idtofind;

	if (Updatenode(idtofind)){
		cout << "\n\Record is updated successfully:\n";
	}
	else {
		cout << "\n Record does not find";
	}

	char updateagain;

	cout << "\n\nDo you want to update another record? [y/n]";    //search again
	cin >> updateagain;
	if (updateagain == 'y')
		return false;
	else if (updateagain == 'n')
		return true;



}
int main()
{
	td r1;

	bool result = false;
	do{
		result = r1.respond();

	} while (result == true);




	return 0;
}

