#include<iostream>
#include<queue>
#include<string>
#include<conio.h>
using namespace std;
struct graph {
	string vertex;
	graph* next;
};
int size_graph(graph* start) {
	int s = 0;
	graph* trav = start;
	while (trav != NULL) {
		s++;
		trav = trav->next;
	}
	return s;
}
string vertex_at_position(graph* start, int pos) {
	if (pos<0 || pos>size_graph(start))
	{
		cout << "Invalid position" << endl;
		return "";
	}
	int temp = 0;
	graph* trav = start;
	while (trav != NULL) {
		if (temp == pos) {
			return trav->vertex;
		}
		trav = trav->next;
		temp++;
	}
	cout << "Invalid position " << endl;
}
void add_vertex_at_end(graph*& start, string data) {
	graph* temp = new graph;
	temp->vertex = data;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else {
		graph* trav = start;
		while (trav->next != NULL) {
			trav = trav->next;
		}
		trav->next = temp;
	}
}
void populate_graph(graph*& start) {
	add_vertex_at_end(start, "F-12"); //0
	add_vertex_at_end(start, "G-12"); //1
	add_vertex_at_end(start, "G-8"); //2
	add_vertex_at_end(start, "F-9");//3
	add_vertex_at_end(start, "G-6");//4
	add_vertex_at_end(start, "H-8");//5
	add_vertex_at_end(start, "F-11");//6
	add_vertex_at_end(start, "F-5");//7
	add_vertex_at_end(start, "I-11");//8
	add_vertex_at_end(start, "H-11");//9
	add_vertex_at_end(start, "I-15");//10
	add_vertex_at_end(start, "I-12");//11
	add_vertex_at_end(start, "I-14");//12
	add_vertex_at_end(start, "I-16");//13
	add_vertex_at_end(start, "F-7");//14
	add_vertex_at_end(start, "I-9");//15
	add_vertex_at_end(start, "F-6");//16
	add_vertex_at_end(start, "H-10");//17
	add_vertex_at_end(start, "G-14");//18
	add_vertex_at_end(start, "H-9");//19
	add_vertex_at_end(start, "I-8");//20
	add_vertex_at_end(start, "G-10");//21
	add_vertex_at_end(start, "G-9");//22
	add_vertex_at_end(start, "F-10");//23
	add_vertex_at_end(start, "F-8");//24
	add_vertex_at_end(start, "G-11");//25
	add_vertex_at_end(start, "I-10");//26
	add_vertex_at_end(start, "H-9");//27
	add_vertex_at_end(start, "G-7"); //28
	add_vertex_at_end(start, "G-5"); //29
	add_vertex_at_end(start, "G-13"); //30

}
class Delivery {
private:
	int numVertices;
	int** adjacencyMatrix;
	
public:
	graph* start;
	Delivery(int vertices = 31) : numVertices(vertices) {
		start = NULL;
		populate_graph(start);
		adjacencyMatrix = new int* [numVertices];
		for (int i = 0; i < numVertices; i++) {
			adjacencyMatrix[i] = new int[numVertices];
		}
		for (int i = 0; i < numVertices; i++) {
			for (int j = 0; j < numVertices; j++)
				adjacencyMatrix[i][j] = 0;
		}
		//hardcoded edges for islamabad city
		addEdge(0, 4, 12); addEdge(1, 19, 8); addEdge(2, 0, 7); addEdge(3, 20, 11); addEdge(4, 3, 6); addEdge(5, 26, 2); addEdge(6, 27, 5); addEdge(7, 24, 15);
		addEdge(8, 15, 7); addEdge(0, 16, 13); addEdge(9, 28, 1); addEdge(10, 1, 3); addEdge(11, 5, 9); addEdge(12, 4, 2);  addEdge(11, 15, 8);
		addEdge(0, 13, 10); addEdge(3, 0, 9); addEdge(6, 22, 10); addEdge(12, 25, 1); addEdge(14, 22, 15); addEdge(15, 17, 4); addEdge(13, 18, 2);
		addEdge(16, 10, 8); addEdge(0, 12, 13); addEdge(3, 9, 10); addEdge(17, 26, 5); addEdge(18, 1, 14); addEdge(9, 30, 1); addEdge(11, 10, 6);
		addEdge(3, 21, 3); addEdge(7, 23, 2);	addEdge(22, 18, 12);	addEdge(15, 6, 14);	addEdge(13, 14, 5);		addEdge(3, 8, 8);	addEdge(19, 28, 2);
		addEdge(20, 25, 10);	addEdge(9, 11, 9);	addEdge(1, 24, 4);	addEdge(23, 14, 6);	addEdge(7, 13, 7);	addEdge(5, 13, 13);
		addEdge(19, 2, 6);	addEdge(8, 24, 4); addEdge(11, 1, 15); addEdge(16, 15, 3); addEdge(12, 11, 8); addEdge(6, 29, 1); addEdge(2, 15, 5); addEdge(5, 29, 11);
		addEdge(23, 6, 6); addEdge(21, 0, 5); addEdge(22, 9, 7); addEdge(19, 3, 11); addEdge(0, 7, 2); addEdge(16, 11, 9);
		addEdge(10, 0, 14); addEdge(29, 12, 12); addEdge(3, 4, 15); addEdge(10, 3, 7); addEdge(2, 28, 2); addEdge(0, 16, 14);
		addEdge(19, 20, 3); addEdge(21, 6, 1); addEdge(20, 10, 2); addEdge(3, 13, 9);	addEdge(19, 26, 3);	addEdge(5, 25, 6);	addEdge(9, 1, 4);	addEdge(15, 1, 7);
		addEdge(20, 2, 10);	addEdge(17, 20, 5);	addEdge(1, 8, 12);	addEdge(26, 7, 15);	addEdge(23, 21, 13);	addEdge(16, 0, 1);	addEdge(12, 9, 2);
		addEdge(25, 23, 5);	addEdge(26, 13, 14);
		addEdge(23, 16, 3);	addEdge(0, 24, 6);	addEdge(24, 16, 7);	addEdge(22, 6, 11);	addEdge(16, 19, 12);	addEdge(24, 22, 4);	addEdge(0, 9, 3);	addEdge(9, 10, 5);
		addEdge(11, 18, 8);	addEdge(4, 3, 10);	addEdge(15, 25, 9);

	}
	// Destructor
	~Delivery() {
		for (int i = 0; i < numVertices; ++i) {

			delete[] adjacencyMatrix[i];
		}
		delete[] adjacencyMatrix;
	}
	// Add an edge to the graph
	void addEdge(int source, int dest, int weight) {

		adjacencyMatrix[source][dest] = weight;
		adjacencyMatrix[dest][source] = weight;
	}
	void findingShortestDistance(int x, int y) {
		// Initialize the predecessor matrix
		int predec[31][31];
		for (int i = 0; i < numVertices; i++) {
			for (int j = 0; j < numVertices; j++) {
				if (adjacencyMatrix[i][j] != 0) {
					predec[i][j] = i;
				}
				else {
					predec[i][j] = -1; // No path initially
				}
			}
		}

		// Applying Floyd-Warshall Algorithm which iterates through i (starting ciyt) , j(intermediate) and k destination city and updates wnitl no change remain in
		//the adjacency matrix if a small path is found then it updates the predecessor adjacency matrix 
		for (int k = 0; k < numVertices; k++) {
			for (int i = 0; i < numVertices; i++) {
				for (int j = 0; j < numVertices; j++) {
					// Skip if there's no path
					if (adjacencyMatrix[i][k] == 0 || adjacencyMatrix[k][j] == 0) 
						continue;

					// Calculate potential shorter path
					int newDistance = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
					if (adjacencyMatrix[i][j] == 0 || newDistance < adjacencyMatrix[i][j]) {
						adjacencyMatrix[i][j] = newDistance;
						predec[i][j] = predec[k][j];
					}
				}
			}
		}

		// Check for existence of a path
		if (adjacencyMatrix[x][y] == 0) {
			cout << "No path exists between " << vertex_at_position(start, x) << " and " << vertex_at_position(start, y) << "." << endl;
			return;
		}

		cout << "Shortest path from " << vertex_at_position(start, x) << " to " << vertex_at_position(start, y) << ": ";
		string path = vertex_at_position(start, y);
		int current = y;
		while (predec[x][current] != x) {
			current = predec[x][current];
			path = vertex_at_position(start, current) + " -> " + path;
		}
		path = vertex_at_position(start, x) + " -> " + path;
		cout << path << endl;
		cout << "Total distance: " << adjacencyMatrix[x][y] << endl;
	}
	int shortestweight(int x, int y) {
		// Initialize the predecessor matrix
		int predec[31][31];
		for (int i = 0; i < numVertices; i++) {
			for (int j = 0; j < numVertices; j++) {
				if (adjacencyMatrix[i][j] != 0) {
					predec[i][j] = i;
				}
				else {
					predec[i][j] = -1; // No path initially
				}
			}
		}

		// Apply Floyd-Warshall Algorithm
		for (int k = 0; k < numVertices; k++) {
			for (int i = 0; i < numVertices; i++) {
				for (int j = 0; j < numVertices; j++) {
					// Skip if there's no path
					if (adjacencyMatrix[i][k] == 0 || adjacencyMatrix[k][j] == 0)
						continue;

					// Calculate potential shorter path
					int newDistance = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
					if (adjacencyMatrix[i][j] == 0 || newDistance < adjacencyMatrix[i][j]) {
						adjacencyMatrix[i][j] = newDistance;
						predec[i][j] = predec[k][j];
					}
				}
			}
		}
    	return adjacencyMatrix[x][y] ;
	}
};

int generate_id() {
	static int id = 11111;
	return id++;
}
string enterpassword() {
	const int passwordLength = 8;
	string password;
	bool isLowercase, isUppercase, isSpecialChar, isNumeric;

	while (true) {
		password.clear();
		isLowercase = isUppercase = isSpecialChar = isNumeric = false;

		cout << "                  Enter the Password: ";

		char c;
		while (password.length() < passwordLength) {
			c = _getch(); // Read character without echoing
			if (c == '\r') { // Enter key pressed
				break;
			}

			password += c;
			cout << '*'; // Mask password input

			// Check character categories
			if (c >= 'A' && c <= 'Z') {
				isUppercase = true;
			}
			else if (c >= 'a' && c <= 'z') {
				isLowercase = true;
			}
			else if (c >= '0' && c <= '9') {
				isNumeric = true;
			}
			else if ((c >= 33 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 126)) {
				isSpecialChar = true;
			}
		}
		cout << endl;

		if (password.length() != passwordLength || !isUppercase || !isLowercase || !isSpecialChar || !isNumeric) {
			cout << "--------- Incorrect Password ---------" << endl;
			if (!isUppercase) {
				cout << "The password must contain at least one uppercase letter." << endl;
			}
			if (!isLowercase) {
				cout << "The password must contain at least one lowercase letter." << endl;
			}
			if (!isSpecialChar) {
				cout << "The password must contain at least one special character." << endl;
			}
			if (!isNumeric) {
				cout << "The password must contain at least one numeric digit." << endl;
			}
			if (password.length() != passwordLength) {
				cout << "The password must be exactly 8 characters long." << endl;
			}
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			continue; // Retry password input
		}

		// If valid, return the password
		return password;
	}
}
struct employee {
	int id;
	string email;
	string name;
	string password;
	employee(int i = 0, string em = "", string na = "", string pass = "") {
		id = i;
		email = em;
		name = na;
		password = pass;
	}
};
struct Employees {
	employee obj;
	Employees* next;
	Employees(const employee& cust) :obj(cust), next(NULL) {}
};
class Hashmap_Empl {
private:
	static const int SIZE = 10;
	Employees* table[SIZE];
	int hashFunc(int key) {
		return key % SIZE;
	}
public:
	Hashmap_Empl() {
		for (int i = 0; i < SIZE; ++i) {
			table[i] = nullptr;
		}
	}
	void insert(const employee& customer) {
		int index = hashFunc(customer.id);
		Employees* newNode = new Employees(customer);

		if (table[index] == nullptr) {
			table[index] = newNode;
		}
		else {
			Employees* current = table[index];
			while (current != nullptr) {
				if (current->next == nullptr)
					break;
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void display() {
		for (int i = 0; i < SIZE; i++) {
			cout << "Index " << i << ": ";
			Employees* current = table[i];
			if (current == nullptr) {
				cout << "Empty" << endl;
			}
			else {
				while (current != nullptr) {
					cout << "ID: " << current->obj.id
						<< ", Name: " << current->obj.name
						<< ", Email: " << current->obj.email << endl;
					current = current->next;
				}
				cout << "NULL" << endl;
			}
		}
	}
	Employees* findCustomer(int id) {
		int index = hashFunc(id);
		Employees* current = table[index];
		while (current != nullptr) {
			if (current->obj.id == id) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}
	void signUp() {
		employee newCustomer;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~SIGN UP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "                    Enter your name  ";
		string n;
		cin >> n;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		newCustomer.name = n;
		newCustomer.password = enterpassword();
		newCustomer.id = generate_id();
		cout << "                    Enter email ";

		string em = "";
		cin >> em;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		newCustomer.email = em;
		cout << "               Please confirm your information " << endl;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		string check_pass = "";
		check_pass = enterpassword();
		if (check_pass != newCustomer.password)
		{
			cout << "      Wrong password" << endl;
			signUp();
		}
		cout << "              Confirm your email ";
		cin >> em;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		if (em != newCustomer.email)
		{
			cout << "      Wrong email" << endl;
			signUp();
		}
		cout << "                Confirm your name ";
		cin >> n;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		if (n != newCustomer.name)
		{
			cout << "      Wrong Name " << endl;
			signUp();
		}
		if (findCustomer(newCustomer.id) != nullptr) {
			cout << "Error: Employee with ID " << newCustomer.id << " already exists!" << endl;
		}
		else {
			insert(newCustomer);
			cout << "              Sign up successful for employee: " << newCustomer.name << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		}
	}
	void login() {
		int idd;
		string passwor;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Enter ID "; cin >> idd;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		passwor = enterpassword();
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		Employees* customerNode = findCustomer(idd);
		if (customerNode == nullptr) {
			cout << "Error: No customer found with ID " << idd << "!" << endl;
			return;
		}
		if (passwor == customerNode->obj.password) {
			cout << "               Login successful! Welcome, " << customerNode->obj.name << "!" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		}
		else {
			cout << "Error: Incorrect password!" << endl;
		}
	}
	void reset_name_pass() {
		string nam = "", pass = ""; int i = 0;
		cout << "           Enter your original id "; cin >> i;
		Employees* customerNode = findCustomer(i);
		if (customerNode == nullptr) {
			cout << "Error: No employee found with entered ID " << i << "!" << endl;
			return;
		}
		cout << "            Enter your new name "; cin >> nam;
		customerNode->obj.name = nam;
		cout << "            Enter your new password " << endl;
		pass = enterpassword();
		customerNode->obj.password = pass;

		cout << "            Your password has been successfully reseted" << endl;

	}
};

struct Dish {
	int id;
	string name;
	double cost;
	string type;
	Dish(int id = 0, string name = "", double cost = 0, string type = "")
		: id(id), name(name), cost(cost), type(type) {}
};
struct menu {
	int id;
	string name;
	int totaldishes;
	Dish* dish;
	int dish_id;
	menu(int id = 0, string name = "", int totaldishes = 0)
		: id(id), name(name), totaldishes(totaldishes), dish(nullptr) {}
};
struct Menu {
	menu* obj;
	Menu* left;
	Menu* right;
	Menu(menu* obj = nullptr) : obj(obj), left(nullptr), right(nullptr) {}
};
Menu* newNode(int id, const string& menuName, const Dish& dishs) {
	Menu* temp = new Menu(new menu(id, menuName, 1));
	temp->obj->dish = new Dish(dishs.id, dishs.name, dishs.cost, dishs.type);
	return temp;
}
void add_dish(Menu*& root, int menuId, const string& menuName, const Dish& dishs) {
	if (root == NULL) {
		root = newNode(menuId, menuName, dishs);
		return;
	}
	queue <Menu*> q;
	q.push(root);
	root->obj->totaldishes++;
	while (!q.empty()) {
		Menu* curr = q.front();
		q.pop();
		if (curr->left != nullptr)
			q.push(curr->left);
		else
		{
			curr->left = newNode(menuId, menuName, dishs);
			return;
		}
		if (curr->right != nullptr)
			q.push(curr->right);
		else
		{
			curr->right = newNode(menuId, menuName, dishs);
			return;
		}
	}

}
void display_menu_helper(Menu* root) {
	if (root != NULL) {
		display_menu_helper(root->left);
		cout << "Dish ID: " << root->obj->dish->id << " Dish Name: " << root->obj->dish->name << "  Dish type: " << root->obj->dish->type << " Dish Cost: " << root->obj->dish->cost << endl;
		display_menu_helper(root->right);
	}
}
void display_menu(Menu* root) {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Menu Id: " << root->obj->id << endl;
	cout << "Menu Name: " << root->obj->name << endl;
	cout << "Menu totaldishes: " << root->obj->totaldishes << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	display_menu_helper(root);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
void deleteDeepest(Menu* root, Menu* deepNode) {
	queue<Menu*> q;
	q.push(root);

	Menu* current;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		if (current == deepNode) {
			current = nullptr;
			delete deepNode;
			return;
		}
		if (current->right) {
			if (current->right == deepNode) {
				current->right = nullptr;
				delete deepNode;
				return;
			}
			q.push(current->right);
		}
		if (current->left) {
			if (current->left == deepNode) {
				current->left = nullptr;
				delete deepNode;
				return;
			}
			q.push(current->left);
		}
	}
}
Menu* delete_dish(Menu*& root, int idd) {
	if (root == nullptr)
		return nullptr;
	queue<Menu*> q;
	q.push(root);

	Menu* idNode = nullptr;
	Menu* deepNode = nullptr;
	Menu* parentNode = nullptr;

	while (!q.empty()) {
		Menu* current = q.front();
		q.pop();
		deepNode = current;

		if (current->obj->dish && current->obj->dish->id == idd)
			idNode = current;

		if (current->left) {
			q.push(current->left);
			if (current->left == deepNode)
				parentNode = current;
		}
		if (current->right) {
			q.push(current->right);
			if (current->right == deepNode)
				parentNode = current;
		}
	}

	if (idNode) {
		idNode->obj->dish->id = deepNode->obj->dish->id;
		idNode->obj->dish->name = deepNode->obj->dish->name;
		idNode->obj->dish->cost = deepNode->obj->dish->cost;
		idNode->obj->dish->type = deepNode->obj->dish->type;
		deleteDeepest(root, deepNode);
		root->obj->totaldishes--;
	}

	return root;
}
void edit_dish(Menu*& root, int id) {
	if (root == NULL)
		return;
	else {
		queue<Menu*>q;
		q.push(root);
		while (!q.empty()) {
			Menu* temp = q.front();
			q.pop();
			if (temp->obj->dish && temp->obj->dish->id == id) {
				int d_cost = 0;
				string d_name = " ", d_type = " ";
				cout << "Enter new dish name" << endl;
				cin >> d_name;
				cout << "Enter new dish type" << endl;
				cin >> d_type;
				cout << "Enter new dish cost" << endl;
				cin >> d_cost;
				temp->obj->dish->cost = d_cost;
				temp->obj->dish->name = d_name;
				temp->obj->dish->type = d_type;
				return;
			}
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}
}
Dish* get_dish_by_id(Menu* root, int dishID, Dish& temp) {
	if (root == nullptr) {
		return nullptr;
	}
	if (root->obj->dish && root->obj->dish->id == dishID) {
		temp.cost = root->obj->dish->cost;
		temp.id = root->obj->dish->id;
		temp.name = root->obj->dish->name;
		temp.type = root->obj->dish->type;
		return root->obj->dish;
	}
	Dish* leftR = get_dish_by_id(root->left, dishID, temp);
	if (leftR != nullptr) {
		return leftR;
	}
	Dish* rightR = get_dish_by_id(root->right, dishID, temp);
	if (rightR != nullptr) {
		return rightR;
	}
	return nullptr;
}
struct restaurant {
	int id;
	string name;
	string type;
	int location;
	Menu* menue;
	employee* Manager;
	employee* driver;
	restaurant(int i = 0, string n = "", string t = "", Menu* men = nullptr, employee* manager = nullptr,employee* drive=nullptr,int lo=0) {
		id = i;
		name = n;
		type = t;
		menue = men;
		Manager = manager;
		driver = drive;
		location = lo;
	}
};
struct Restaurants {
	restaurant* obj;
	Restaurants* next;
};
void add_restaurant(Restaurants*& start, const restaurant& newRestaurant) {
	Restaurants* temp = new Restaurants;
	temp->obj = new restaurant(newRestaurant.id, newRestaurant.name, newRestaurant.type, newRestaurant.menue); // Dynamically allocate the restaurant object
	temp->next = NULL;

	if (start == NULL) {
		start = temp;
	}
	else {
		Restaurants* trav = start;
		while (trav->next != NULL) {
			trav = trav->next;
		}
		trav->next = temp;
	}
}
void delete_at_end(Restaurants*& start) {
	if (start == NULL)
		cout << "no node" << endl;
	else {
		Restaurants* last = start;
		Restaurants* previous = start;
		while (last->next != NULL) {
			previous = last;
			last = last->next;
		}
		previous->next = NULL;
		delete last;
	}
}
void delete_at_front(Restaurants*& start) {
	if (start == NULL)
		cout << "no node" << endl;
	else {
		Restaurants* temp = start;
		temp = temp->next;
		delete start;
		start = temp;
	}
}
int size_restaurant(Restaurants* start) {
	if (start == NULL)
		return 0;
	else {
		int count = 0;
		Restaurants* traverse = start;
		while (traverse != NULL) {
			traverse = traverse->next;
			count++;
		}
		return count;
	}

}
void delete_in_mid(Restaurants*& start, int position) {
	if (position >= 1 && position <= size_restaurant(start)) {
		if (position == 1)
			delete_at_front(start);
		else if (position == size_restaurant(start))
			delete_at_end(start);
		else {
			Restaurants* previous = start;
			Restaurants* last = start;
			int i = 1;
			while (i < position) {
				previous = last;
				last = last->next;
				i++;
			}
			previous->next = last->next;
			delete last;
		}
	}
	else
		cout << "invalid position" << endl;
}
void delete_restaurant_based_name(Restaurants*& start, string name) {
	//restaurant is deleted based on name
	int position = 1;
	Restaurants* trav = start;
	while (trav != NULL) {
		if (trav->obj->name == name) {
			delete_in_mid(start, position);
			cout << "Restaurant " << name << " successfully deleted" << endl;
			break;
		}
		trav = trav->next;
		position++;
	}

}
void display_restaurants(Restaurants* start) {
	if (start == NULL) {
		cout << "No restaurants" << endl;
		return;
	}
	Restaurants* trav = start;
	while (trav != NULL) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Restaurants~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Restaurant Name: " << trav->obj->name << endl;
		cout << "Restaurant ID: " << trav->obj->id << endl;
		cout << "Restaurant Type: " << trav->obj->type << endl;
		display_menu(trav->obj->menue);
		trav = trav->next;
	}
}
void edit_restaurant(Restaurants*& start, int id) {
	Restaurants* trav = start;
	while (trav != NULL) {
		if (trav->obj->id == id) {
			cout << "Enter new name of the restaurant" << endl;
			string n;
			cin >> n;
			trav->obj->name = n;
			cout << "Enter new type of the restaurant" << endl;
			cin >> n;
			trav->obj->type = n;
			return;
		}
		trav = trav->next;
	}
}
struct promotion {
	int id;
	string name;
	double discount;
	int limit;
	promotion(int i = 0, string n = "", double dis = 0, int lim = 0) : id(i), name(n), discount(dis), limit(lim) {
	}
};
struct Promotions {
	promotion* obj;
	Promotions* next;
	Promotions() {
		obj = nullptr;
		next = nullptr;
	}
};
void promotion_push(Promotions*& start, const promotion& prom) {
	Promotions* temp = new Promotions;
	temp->obj = new promotion(prom.id, prom.name, prom.discount, prom.limit);
	temp->next = NULL;
	if (start == NULL) {
		start = temp;
		return;
	}
	else {
		Promotions* trav = start;
		while (trav->next != NULL)
			trav = trav->next;
		trav->next = temp;
	}
}
int size_promotion(Promotions*& start) {
	Promotions* trav = start; int size = 0;
	while (trav != NULL) {
		trav = trav->next;
		size++;
	}
	return size;
}
promotion* promotion_pop(Promotions*& start) {
	if (start == NULL)
		cout << "no node" << endl;
	else {
		Promotions* last = start;
		Promotions* previous = start;
		while (last->next != NULL) {
			previous = last;
			last = last->next;
		}
		last->obj->limit--;
		//decreasing the limit before returning it
		promotion* temp = new promotion(last->obj->id, last->obj->name, last->obj->discount, last->obj->limit);
		//if limit is less than 0 than delete it otherwise not
		if (last->obj->limit <= 0)
		{
			previous->next = NULL;
			delete last;
		}
		return temp;
	}
}
void view_promotions(Promotions* start) {
	Promotions* trav = start;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Promotions~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	while (trav != NULL)
	{
		cout << "Promotion ID :" << trav->obj->id << " Name :" << trav->obj->name << " Discount: " << trav->obj->discount << " Limit: " << trav->obj->limit << endl;
		trav = trav->next;
	}
}
void populate_promotions(Promotions*& start) {
	promotion p1(generate_id(), "Holiday Sale", 20.5, 5);
	promotion p2(generate_id(), "Black Friday Deal", 50.0, 3);
	promotion p3(generate_id(), "Summer Discount", 15.0, 7);
	promotion p4(generate_id(), "New Year Special", 25.0, 10);

	promotion_push(start, p1);
	promotion_push(start, p2);
	promotion_push(start, p3);
	promotion_push(start, p4);
}
void delete_at_end_promotion(Promotions*& start) {
	if (start == NULL)
		cout << "no node" << endl;
	else {
		Promotions* last = start;
		Promotions* previous = start;
		while (last->next != NULL) {
			previous = last;
			last = last->next;
		}
		previous->next = NULL;
		delete last;
	}
}
void delete_at_front_promotion(Promotions*& start) {
	if (start == NULL)
		cout << "no node" << endl;
	else {
		Promotions* temp = start;
		temp = temp->next;
		delete start;
		start = temp;
	}
}
void delete_in_mid_promotion(Promotions*& start, int position) {
	if (position >= 1 && position <= size_promotion(start)) {
		if (position == 1)
			delete_at_front_promotion(start);
		else if (position == size_promotion(start))
			delete_at_end_promotion(start);
		else {
			Promotions* previous = start;
			Promotions* last = start;
			int i = 1;
			while (i < position) {
				previous = last;
				last = last->next;
				i++;
			}
			previous->next = last->next;
			delete last;
		}
	}
	else
		cout << "invalid position" << endl;
}
void delete_promotion(Promotions*& start) {
	cout << "  Enter the name of promotion you want to delete" << endl;
	string pname = "";
	cin.ignore();
	getline(cin, pname);
	int position = 1;
	Promotions* trav = start;
	while (trav != NULL) {
		if (trav->obj->name == pname) {
			delete_in_mid_promotion(start, position);
			cout << "Promotion " << pname << " successfully deleted" << endl;
			break;
		}
		trav = trav->next;
		position++;
	}
}
struct order {
	int id;
	Dish dishes[10];//an order can't contain more than 10 dishes
	double total_cost;
	int type;//3 for Premium ,2 for express,1 for normal
	string status;
	employee* emplo;
	employee* delivery_boy;
	int weight;
	int location_for_order_delivery;
	order(int i = 0, double total_c = 0, int ty = 1) {
		id = i;
		total_cost = total_c;
		type = ty;
		status = "Not completed";
		emplo = nullptr;
		delivery_boy = nullptr;
		location_for_order_delivery = 0;
		weight = 0;
	}
};
struct Orders {
	order array[100];
	int front;
	int rear;
	int num_of_orders;
	//customer 
	//employee
	Orders() {
		front = 0;
		rear = 99;
		num_of_orders = 0;
	}
};
double calc_cost_order(order obj) {
	double cost_temp = 0;
	for (int i = 0; i < 10; i++) {
		if (obj.dishes[i].name != "")
			cost_temp += obj.dishes[i].cost;
	}
	if (obj.type == 3)
		cost_temp += 500;
	if (obj.type == 2)
	{
		cost_temp += 0.1 * cost_temp;
	}
	return cost_temp;
}
void sort_order(Orders* obj) {
	//orders are sorted based on their type which means priority
	if (obj->num_of_orders == 0 || obj->num_of_orders == 1)
		return;
	else {
		int f = obj->front;
		int r = obj->rear;
		for (int i = 0; i < obj->num_of_orders - 1; i++) {
			for (int j = i + 1; j < obj->num_of_orders; j++) {
				if (obj->array[i].type < obj->array[j].type) {
					order temp = obj->array[j];
					obj->array[j] = obj->array[i];
					obj->array[i] = temp;
				}
			}
		}
	}
}
void enqueue_order(Orders* obj, order arr) {
	if (obj->num_of_orders == 100)
		return;

	if (obj->num_of_orders == 0) {
		obj->num_of_orders++;
		obj->rear = 0;
		arr.total_cost = calc_cost_order(arr);
		obj->array[obj->rear] = arr;

	}
	else {
		if (obj->rear == 99) {
			obj->rear = 0;
			obj->array[obj->rear] = arr;
			obj->array[obj->rear].total_cost = calc_cost_order(arr);
			obj->num_of_orders++;
		}
		else {
			obj->array[++obj->rear] = arr;
			obj->array[obj->rear].total_cost = calc_cost_order(arr);
			obj->num_of_orders++;
		}
	}
	sort_order(obj);
}
void display_order(Orders* obj) {
	int i = obj->front;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Orders~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {
		cout << "Order " << j + 1 << " :" << endl;
		cout << "Order ID: " << obj->array[i].id << " Total Cost: " << obj->array[i].total_cost << "  Order status: " << obj->array[i].status << endl;
		for (int k = 0; k < 10; k++)
		{
			if (obj->array[i].dishes[k].name != "")
				cout << obj->array[i].dishes[k].name << " " << obj->array[i].dishes[k].cost << "  ";
		}
		cout << endl;
		if (i == 99)
			i = 0;
		else
			i++;
		cout << " ";
	}
	cout << endl;
}
void display_particular_order(Orders* obj, int idfind) {
	int i = obj->front;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Order~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {
		if (obj->array[i].id == idfind)
		{
			cout << "Order ID: " << obj->array[i].id << " Total Cost: " << obj->array[i].total_cost << " Order Status: " << obj->array[i].status << endl;
			for (int k = 0; k < 10; k++)
			{
				if (obj->array[i].dishes[k].name != "")
					cout << obj->array[i].dishes[k].name << " " << obj->array[i].dishes[k].cost << "  ";
			}
			cout << endl;
		}
		if (i == 99)
			i = 0;
		else
			i++;
	}
}
void complete_order(Orders* obj, int idfind, Promotions* start) {
	if (obj->num_of_orders == 0) {
		cout << "No orders to complete!" << endl;
		return;
	}
	promotion* apply = promotion_pop(start);
	int discount_to_apply = apply->discount;
	int i = obj->front;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Order~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {
		if (obj->array[i].id == idfind)
		{
			obj->array[i].status = "Completed";
			cout << "Confirming your Order ID: " << obj->array[i].id << " Total Cost: " << obj->array[i].total_cost << endl;
			int discounted_price = obj->array[i].total_cost;
			discounted_price -= obj->array[i].total_cost * (discount_to_apply * 0.01);
			obj->array[i].total_cost = discounted_price;
			cout << " Your total cost after applying promotion " << apply->name << " is " << discounted_price << endl;
			if (obj->array[i].type == 3) {
				cout << " your cost after applying delivery charges is still the same being premium" << endl;
			}
			else if (obj->array[i].type == 2) {
				cout << " your cost after applying delivery charges is "<< obj->array[i].total_cost+200 << endl;
				obj->array[i].total_cost += 200;
			}
			else if (obj->array[i].type == 1) {
				cout << " your cost after applying delivery charges is " << obj->array[i].total_cost +100 << endl;
				obj->array[i].total_cost += 100;
			}

			if (obj->array[i].type == 3) {
				cout << " your final cost after applying premimum charges is "<< obj->array[i].total_cost + 500 << endl;
				obj->array[i].total_cost += 500;
			}
			else if (obj->array[i].type == 2) {
				cout << " your cost after applying express charges is " << obj->array[i].total_cost + 0.1* obj->array[i].total_cost << endl;
				obj->array[i].total_cost += 0.1 * obj->array[i].total_cost;
			}
			else if (obj->array[i].type == 1) {
				cout << " your cost after applying normal charges is still the same " << obj->array[i].total_cost  << endl;

			}
			cout << " Your order is processed by employee " << obj->array[i].emplo->name << endl;
			for (int k = 0; k < 10; k++)
			{
				if (obj->array[i].dishes[k].name != "")
					cout << obj->array[i].dishes[k].name << " " << obj->array[i].dishes[k].cost << "  ";
			}
			cout << endl;
		}
		if (i == 99)
			i = 0;
		else
			i++;
	}
	cout << " Your order is processed successfully.  " << endl;
}
void display_particular_restaurant_order(Orders* obj, int employee_id) {
	int i = obj->front;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Orders~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {
		if (obj->array[i].emplo->id == employee_id)
		{
			cout << "Order " << j + 1 << " :" << endl;
			cout << "Order ID: " << obj->array[i].id << " Total Cost: " << obj->array[i].total_cost << "  Order status: " << obj->array[i].status << endl;
			for (int k = 0; k < 10; k++)
			{
				if (obj->array[i].dishes[k].name != "")
					cout << obj->array[i].dishes[k].name << " " << obj->array[i].dishes[k].cost << "  ";
			}
			cout << endl;
		}
		if (i == 99)
			i = 0;
		else
			i++;
		cout << " ";
	}
	cout << endl;
}
void display_particular_restaurant_processed_order(Orders* obj, int employee_id) {
	int i = obj->front;
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Orders~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {
		if (obj->array[i].emplo->id == employee_id && obj->array[i].status == "Completed")
		{
			cout << "Order " << j + 1 << " :" << endl;
			cout << "Order ID: " << obj->array[i].id << " Total Cost: " << obj->array[i].total_cost << "  Order status: " << obj->array[i].status << endl;
			for (int k = 0; k < 10; k++)
			{
				if (obj->array[i].dishes[k].name != "")
					cout << obj->array[i].dishes[k].name << " " << obj->array[i].dishes[k].cost << "  ";
			}
			cout << endl;
			
		}
		if (i == 99)
			i = 0;
		else
			i++;
		cout << " ";
	}
	cout << endl;
}
void display_particular_restaurant_current_order(Orders* obj, int employee_id) {
	int i = obj->front;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Orders~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {
		if (obj->array[i].emplo->id == employee_id)
		{
			cout << "Order " << j + 1 << " :" << endl;
			cout << "Order ID: " << obj->array[i].id << " Total Cost: " << obj->array[i].total_cost << "  Order status: " << obj->array[i].status << endl;
			for (int k = 0; k < 10; k++)
			{
				if (obj->array[i].dishes[k].name != "")
					cout << obj->array[i].dishes[k].name << " " << obj->array[i].dishes[k].cost << "  ";
			}
			cout << endl;
			return;
		}
		if (i == 99)
			i = 0;
		else
			i++;
		cout << " ";
	}
	cout << endl;
}
void display_particular_restaurant_order_delivery(Orders* obj, int employee_id) {
	int i = obj->front;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Orders~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {
		if (obj->array[i].delivery_boy->id == employee_id)
		{
			cout << "Order " << j + 1 << " :" << endl;
			cout << "Order ID: " << obj->array[i].id << " Total Cost: " << obj->array[i].total_cost << "  Order status: " << obj->array[i].status << endl;
			for (int k = 0; k < 10; k++)
			{
				if (obj->array[i].dishes[k].name != "")
					cout << obj->array[i].dishes[k].name << " " << obj->array[i].dishes[k].cost << "  ";
			}
			cout << endl;
		}
		if (i == 99)
			i = 0;
		else
			i++;
		cout << " ";
	}
	cout << endl;
		
}
void assigningweights(Orders*& obj, int currentOrderIndex) {
	Delivery o;
	int i = obj->front;
	for (int j = 0; j < obj->num_of_orders; j++) {
		obj->array[i].weight = o.shortestweight(currentOrderIndex, obj->array[i].location_for_order_delivery);
		if (i == 99)
			i = 0;
		else
			i++;
	}
}
int min_weight_order_index(Orders*& obj,int driverid) {
	int minindex = 99;
	int minweight = 999;
	int i = obj->front;
	for (int j = 0; j < obj->num_of_orders; j++) {
		if(obj->array[i].delivery_boy->id==driverid)
		{
			if (obj->array[i].weight < minweight && obj->array[i].status == "Completed")
			{
				minindex = i; minweight = obj->array[i].weight;
			}
		}
		if (i == 99)
			i = 0;
		else
			i++;
	}
	return minindex;
}
void display_particular_restaurant_processed_order_delivery(Orders*obj, int employee_id) {
	int currentOrderIndex ;
	if (employee_id == 60000)
		currentOrderIndex = 0;
	else if (employee_id == 70000)
		currentOrderIndex = 1;
	else if (employee_id == 80000)
		currentOrderIndex = 2;
	else if (employee_id == 90000)
		currentOrderIndex = 3;
	Delivery o;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Orders Path~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {	
			assigningweights(obj, currentOrderIndex);
			int min_index = min_weight_order_index(obj, employee_id);		
			if (min_weight_order_index(obj, employee_id) == 99)
				return;
			if (  obj->array[min_index].status == "Completed")
			{
				cout << "Order " << j + 1 << " :" << endl;
				cout << "Order ID: " << obj->array[min_index].id << " Total Cost: " << obj->array[min_index].total_cost << "  Order status: " << obj->array[min_index].status << endl;
				for (int k = 0; k < 10; k++)
				{
					if (obj->array[min_index].dishes[k].name != "")
						cout << obj->array[min_index].dishes[k].name << " " << obj->array[min_index].dishes[k].cost << "  ";
				}
				cout << endl;
				o.findingShortestDistance(currentOrderIndex, obj->array[min_index].location_for_order_delivery);
				currentOrderIndex = obj->array[min_index].location_for_order_delivery;
				obj->array[min_index].status = "Delivered";
			}
	}
}
void display_particular_restaurant_current_order_delivery(Orders* obj, int employee_id) {
	int i = obj->front;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Orders~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int j = 0; j < obj->num_of_orders; j++) {
		if (obj->array[i].delivery_boy->id == employee_id)
		{
			cout << "Order " << j + 1 << " :" << endl;
			cout << "Order ID: " << obj->array[i].id << " Total Cost: " << obj->array[i].total_cost << "  Order status: " << obj->array[i].status << endl;
			for (int k = 0; k < 10; k++)
			{
				if (obj->array[i].dishes[k].name != "")
					cout << obj->array[i].dishes[k].name << " " << obj->array[i].dishes[k].cost << "  ";
			}
			cout << endl;
			return;
		}
		if (i == 99)
			i = 0;
		else
			i++;
		cout << " ";
	}
	cout << endl;
}
struct review {
	int id;
	int rating;
	string description;
	restaurant* rest;
	review(int i = 0, int r = 0, string d = "") :id(i), rating(r), description(d), rest(nullptr) {
	}
};
//for good reviews max heap is created
struct Reviews_good {
	review* obj;
	Reviews_good* left;
	Reviews_good* right;
	Reviews_good(review* r) : obj(r), left(nullptr), right(nullptr) {}
};
//for bad reviews min heap is created the reviews with lowest rating is going to be at the top
struct Reviews_bad {
	review* obj;
	Reviews_bad* left;
	Reviews_bad* right;
	Reviews_bad(review* r) : obj(r), left(nullptr), right(nullptr) {}
};
Reviews_good* newNode_good(int id, int rate, string dec, const restaurant& res) {
	review* new_review = new review(id, rate, dec);
	new_review->rest = new restaurant(res);
	Reviews_good* temp = new Reviews_good(new_review);
	return temp;
}
Reviews_bad* newNode_bad(int id, int rate, string dec, const restaurant& res) {
	review* new_review = new review(id, rate, dec);
	new_review->rest = new restaurant(res);
	Reviews_bad* temp = new Reviews_bad(new_review);
	return temp;
}
void heapify_good(Reviews_good*& root) {
	if (root == NULL)
		return;
	Reviews_good* greater = root;
	if (root->left && root->left->obj->rating > greater->obj->rating)
		greater = root->left;
	if (root->right && root->right->obj->rating > greater->obj->rating)
		greater = root->right;

	if (greater != root) {
		swap(root->obj, greater->obj);
		heapify_good(greater);
	}
}
void heapify_bad(Reviews_bad*& root) {
	if (root == NULL)
		return;
	Reviews_bad* greater = root;
	if (root->left && root->left->obj->rating < greater->obj->rating)
		greater = root->left;
	if (root->right && root->right->obj->rating < greater->obj->rating)
		greater = root->right;

	if (greater != root) {
		swap(root->obj, greater->obj);
		heapify_bad(greater);
	}
}
void add_review(Reviews_good*& gdRoot, Reviews_bad*& bdRoot, int rate, string desc, const restaurant& res) {
	int id = generate_id();
	if (rate >= 4) {
		if (gdRoot == NULL)
		{
			gdRoot = newNode_good(id, rate, desc, res);
			return;
		}
		queue <Reviews_good*> q;
		q.push(gdRoot);
		while (!q.empty()) {
			Reviews_good* curr = q.front();
			q.pop();
			if (curr->left != nullptr)
				q.push(curr->left);
			else
			{
				curr->left = newNode_good(id, rate, desc, res);
				return;
			}
			if (curr->right != nullptr)
				q.push(curr->right);
			else
			{
				curr->right = newNode_good(id, rate, desc, res);
				return;
			}
		}
		heapify_good(gdRoot);
	}
	else {
		if (bdRoot == NULL)
		{
			bdRoot = newNode_bad(id, rate, desc, res);
			return;
		}
		queue <Reviews_bad*> q;
		q.push(bdRoot);
		while (!q.empty()) {
			Reviews_bad* curr = q.front();
			q.pop();
			if (curr->left != nullptr)
				q.push(curr->left);
			else
			{
				curr->left = newNode_bad(id, rate, desc, res);
				return;
			}
			if (curr->right != nullptr)
				q.push(curr->right);
			else
			{
				curr->right = newNode_bad(id, rate, desc, res);
				return;
			}
		}
		heapify_bad(bdRoot);
	}
}
void edit_review(Reviews_good*& gdRoot, Reviews_bad*& bdRoot, int id) {
	//even if you are editing a review keep in mind that good review will remain good and bad review will remain bad
	if (gdRoot == NULL && bdRoot == NULL)
		return;
	else {
		if (gdRoot != NULL)
		{
			queue<Reviews_good*>q;
			q.push(gdRoot);
			while (!q.empty()) {
				Reviews_good* temp = q.front();
				q.pop();
				if (temp->obj && temp->obj->id == id) {
					int d_cost = 0;
					string d_name = " ";
					cout << "Enter new rating" << endl;
					cin >> d_cost;
					cout << "Enter new description or your review" << endl;
					cin >> d_name;
					temp->obj->rating = d_cost;
					temp->obj->description = d_name;
					return;
				}
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
			heapify_good(gdRoot);
		}
		if (bdRoot != NULL) {
			queue<Reviews_bad*>q;
			q.push(bdRoot);
			while (!q.empty()) {
				Reviews_bad* temp = q.front();
				q.pop();
				if (temp->obj && temp->obj->id == id) {
					int d_cost = 0;
					string d_name = " ";
					cout << "Enter new rating" << endl;
					cin >> d_cost;
					cout << "Enter new description or your review" << endl;
					cin >> d_name;
					temp->obj->rating = d_cost;
					temp->obj->description = d_name;
					return;
				}
				if (temp->left)
					q.push(temp->left);
				if (temp->right)
					q.push(temp->right);
			}
			heapify_bad(bdRoot);
		}
	}
}
void delete_deep(Reviews_good* root, Reviews_good* deepNode) {
	queue<Reviews_good*> q;
	q.push(root);

	Reviews_good* current;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		if (current == deepNode) {
			current = nullptr;
			delete deepNode;
			return;
		}
		if (current->right) {
			if (current->right == deepNode) {
				current->right = nullptr;
				delete deepNode;
				return;
			}
			q.push(current->right);
		}
		if (current->left) {
			if (current->left == deepNode) {
				current->left = nullptr;
				delete deepNode;
				return;
			}
			q.push(current->left);
		}
	}
}
Reviews_good* delete_review(Reviews_good*& root, int idd) {
	if (root == nullptr)
		return nullptr;
	queue<Reviews_good*> q;
	q.push(root);

	Reviews_good* idNode = nullptr;
	Reviews_good* deepNode = nullptr;
	Reviews_good* parentNode = nullptr;

	while (!q.empty()) {
		Reviews_good* current = q.front();
		q.pop();
		deepNode = current;

		if (current->obj && current->obj->id == idd)
			idNode = current;

		if (current->left) {
			q.push(current->left);
			if (current->left == deepNode)
				parentNode = current;
		}
		if (current->right) {
			q.push(current->right);
			if (current->right == deepNode)
				parentNode = current;
		}
	}
	if (idNode) {
		idNode->obj->id = deepNode->obj->id;
		idNode->obj->rating = deepNode->obj->rating;
		idNode->obj->description = deepNode->obj->description;
		delete_deep(root, deepNode);
	}
	return root;
}
void delete_deep(Reviews_bad* root, Reviews_bad* deepNode) {
	queue<Reviews_bad*> q;
	q.push(root);

	Reviews_bad* current;
	while (!q.empty()) {
		current = q.front();
		q.pop();
		if (current == deepNode) {
			current = nullptr;
			delete deepNode;
			return;
		}
		if (current->right) {
			if (current->right == deepNode) {
				current->right = nullptr;
				delete deepNode;
				return;
			}
			q.push(current->right);
		}
		if (current->left) {
			if (current->left == deepNode) {
				current->left = nullptr;
				delete deepNode;
				return;
			}
			q.push(current->left);
		}
	}
}
Reviews_bad* delete_review(Reviews_bad*& root, int idd) {
	if (root == nullptr)
		return nullptr;
	queue<Reviews_bad*> q;
	q.push(root);

	Reviews_bad* idNode = nullptr;
	Reviews_bad* deepNode = nullptr;
	Reviews_bad* parentNode = nullptr;

	while (!q.empty()) {
		Reviews_bad* current = q.front();
		q.pop();
		deepNode = current;

		if (current->obj && current->obj->id == idd)
			idNode = current;

		if (current->left) {
			q.push(current->left);
			if (current->left == deepNode)
				parentNode = current;
		}
		if (current->right) {
			q.push(current->right);
			if (current->right == deepNode)
				parentNode = current;
		}
	}
	if (idNode) {
		idNode->obj->id = deepNode->obj->id;
		idNode->obj->rating = deepNode->obj->rating;
		idNode->obj->description = deepNode->obj->description;
		delete_deep(root, deepNode);
	}
	return root;
}
void display_top_5_bad_and_good_reviews(Reviews_good* gdRoot, Reviews_bad* bdRoot) {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Reviews~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Good Reviews: " << endl;
	if (gdRoot != nullptr) {
		int count = 0;
		queue<Reviews_good*> q;
		q.push(gdRoot);

		while (!q.empty() && count < 5) {
			Reviews_good* curr = q.front();
			q.pop();

			cout << "Review ID: " << curr->obj->id
				<< " Rating: " << curr->obj->rating
				<< " Description: " << curr->obj->description
				<< " Restaurant Name: " << curr->obj->rest->name
				<< endl;

			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
			count++;
		}
	}
	cout << "Bad Reviews: " << endl;
	if (bdRoot != nullptr) {
		int count = 0;
		queue<Reviews_bad*> q;
		q.push(bdRoot);
		while (!q.empty() && count < 5) {
			Reviews_bad* curr = q.front();
			q.pop();
			cout << "Review ID: " << curr->obj->id
				<< " Rating: " << curr->obj->rating
				<< " Description: " << curr->obj->description
				<< " Restaurant Name: " << curr->obj->rest->name << endl;
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
			count++;
		}
	}
}
//delete review
struct customer {
	int id;
	string email;
	string name;
	string password;
	customer(int i = 0, string em = "", string na = "", string pass = "") {
		id = i;
		email = em;
		name = na;
		password = pass;
	}
};
struct Customers {
	customer obj;
	Customers* next;
	Customers(const customer& cust) :obj(cust), next(NULL) {}
};
class Hashmap_Cust {
private:
	static const int SIZE = 10;
	Customers* table[SIZE];
	int hashFunc(int key) {
		return key % SIZE;
	}
public:
	Hashmap_Cust() {
		for (int i = 0; i < SIZE; ++i) {
			table[i] = nullptr;
		}
	}
	void insert(const customer& customer) {
		int index = hashFunc(customer.id);
		Customers* newNode = new Customers(customer);

		if (table[index] == nullptr) {
			table[index] = newNode;
		}
		else {
			Customers* current = table[index];
			while (current != nullptr) {
				if (current->next == nullptr)
					break;
				current = current->next;
			}
			current->next = newNode;
		}
		cout << "Customer with ID " << customer.id << " inserted successfully!" << endl;
	}
	void display() {
		for (int i = 0; i < SIZE; i++) {
			cout << "Index " << i << ": ";
			Customers* current = table[i];
			if (current == nullptr) {
				cout << "Empty" << endl;
			}
			else {
				while (current != nullptr) {
					cout << "ID: " << current->obj.id
						<< ", Name: " << current->obj.name
						<< ", Email: " << current->obj.email << endl;
					current = current->next;
				}
				cout << "NULL" << endl;
			}
		}
	}
	Customers* findCustomer(int id) {
		int index = hashFunc(id);
		Customers* current = table[index];
		while (current != nullptr) {
			if (current->obj.id == id) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}
	void signUp() {
		customer newCustomer;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SIGN UP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "                    Enter your name  ";

		string n;
		cin >> n;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		newCustomer.name = n;
		newCustomer.password = enterpassword();
		newCustomer.id = generate_id();

		cout << "                     Enter email ";

		string em = "";
		cin >> em;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		newCustomer.email = em;
		cout << "               Please confirm your information " << endl;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		string check_pass = "";
		check_pass = enterpassword();
		if (check_pass != newCustomer.password)
		{
			cout << "      Wrong password" << endl;
			signUp();
		}
		cout << "                Confirm your email ";
		cin >> em;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		if (em != newCustomer.email)
		{
			cout << "      Wrong email" << endl;
			signUp();
		}
		cout << "                Confirm your name ";
		cin >> n;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		if (n != newCustomer.name)
		{
			cout << "      Wrong Name " << endl;
			signUp();
		}
		if (findCustomer(newCustomer.id) != nullptr) {
			cout << "Error: Customer with ID " << newCustomer.id << " already exists!" << endl;
		}
		else {
			insert(newCustomer);
			cout << "               Sign up successful for customer: " << newCustomer.name << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		}
	}
	void login() {
		int idd;
		string passwor;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Enter ID "; cin >> idd;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		passwor = enterpassword();
		Customers* customerNode = findCustomer(idd);
		if (customerNode == nullptr) {
			cout << "Error: No customer found with ID " << idd << "!" << endl;
			return;
		}
		if (passwor == customerNode->obj.password) {
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Login successful! Welcome, " << customerNode->obj.name << "!" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		}
		else {
			cout << "Error: Incorrect password!" << endl;
		}
	}
	void reset_name_pass() {
		string nam = "", pass = ""; int i = 0;
		cout << "           Enter your original id "; cin >> i;
		Customers* customerNode = findCustomer(i);
		if (customerNode == nullptr) {
			cout << "Error: No customer found with entered ID " << i << "!" << endl;
			return;
		}
		cout << "            Enter your new name "; cin >> nam;
		customerNode->obj.name = nam;
		cout << "            Enter your new password " << endl;
		pass = enterpassword();
		customerNode->obj.password = pass;

		cout << "            Your password has been successfully reseted" << endl;

	}
};

struct admin {
	int id;
	string email;
	string name;
	string password;
	admin(int i = 0, string em = "", string na = "", string pass = "") {
		id = i;
		email = em;
		name = na;
		password = pass;
	}
};
struct Admins {
	admin obj;
	Admins* next;
	Admins(const admin& cust) :obj(cust), next(NULL) {}
};
class Hashmap_Adm {
private:
	static const int SIZE = 10;
	Admins* table[SIZE];
	int hashFunc(int key) {
		return key % SIZE;
	}
public:
	Hashmap_Adm() {
		for (int i = 0; i < SIZE; ++i) {
			table[i] = nullptr;
		}
	}
	void insert(const admin& customer) {
		int index = hashFunc(customer.id);
		Admins* newNode = new Admins(customer);

		if (table[index] == nullptr) {
			table[index] = newNode;
		}
		else {
			Admins* current = table[index];
			while (current != nullptr) {
				if (current->next == nullptr)
					break;
				current = current->next;
			}
			current->next = newNode;
		}
	}
	void display() {
		for (int i = 0; i < SIZE; i++) {
			cout << "Index " << i << ": ";
			Admins* current = table[i];
			if (current == nullptr) {
				cout << "Empty" << endl;
			}
			else {
				while (current != nullptr) {
					cout << "ID: " << current->obj.id
						<< ", Name: " << current->obj.name
						<< ", Email: " << current->obj.email << endl;
					current = current->next;
				}
				cout << "NULL" << endl;
			}
		}
	}
	Admins* findCustomer(int id) {
		int index = hashFunc(id);
		Admins* current = table[index];
		while (current != nullptr) {
			if (current->obj.id == id) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}
	void signUp() {
		admin newCustomer;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~SIGN UP~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "                    Enter your name  ";
		string n;
		cin >> n;
		newCustomer.name = n;
		newCustomer.password = enterpassword();
		newCustomer.id = generate_id();
		cout << endl << "                     Enter email ";
		string em = "";
		cin >> em;
		newCustomer.email = em;
		cout << "             Please confirm your information " << endl;
		string check_pass = "";
		check_pass = enterpassword();
		if (check_pass != newCustomer.password)
		{
			cout << "      Wrong password" << endl;
			signUp();
		}
		cout << "              Confirm your email ";
		cin >> em;
		if (em != newCustomer.email)
		{
			cout << "      Wrong email" << endl;
			signUp();
		}
		cout << "                Confirm your name ";
		cin >> n;
		if (n != newCustomer.name)
		{
			cout << "      Wrong Name " << endl;
			signUp();
		}
		if (findCustomer(newCustomer.id) != nullptr) {
			cout << "Error: Admin with ID " << newCustomer.id << " already exists!" << endl;
		}
		else {
			insert(newCustomer);
			cout << "Sign up successful for admin: " << newCustomer.name << endl;
		}
	}
	void login() {
		int idd;
		string passwor;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "                Enter ID "; cin >> idd;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		passwor = enterpassword();
		Admins* customerNode = findCustomer(idd);
		if (customerNode == nullptr) {
			cout << "Error: No admin found with ID " << idd << "!" << endl;
			return;
		}
		if (passwor == customerNode->obj.password) {
			cout << "Login successful! Welcome, " << customerNode->obj.name << "!" << endl;
		}
		else {
			cout << "Error: Incorrect password!" << endl;
		}
	}
	void reset_name_pass() {
		string nam = "", pass = ""; int i = 0;
		cout << "           Enter your original id "; cin >> i;
		Admins* customerNode = findCustomer(i);
		if (customerNode == nullptr) {
			cout << "Error: No Admin found with entered ID " << i << "!" << endl;
			return;
		}
		cout << "            Enter your new name "; cin >> nam;
		customerNode->obj.name = nam;
		cout << "            Enter your new password " << endl;
		pass = enterpassword();
		customerNode->obj.password = pass;

		cout << "            Your password has been successfully reseted" << endl;

	}
};

class Menu_for_main {
private:
	Delivery deliver;
	Hashmap_Cust cust;
	Hashmap_Empl emp;
	Hashmap_Adm adm;
	Orders orders;
	bool logged;
	Menu* menu1;
	Menu* menu2;
	Menu* menu3;
	Menu* menu4;
	Restaurants* start;
	Reviews_good* gdroot;
	Reviews_bad* bdroot;
	Promotions* startt;

public:
	Menu_for_main() {
		//prepopulated employees employee1 is of restaurant1, employee2 is of restaurant 2 , employee 3 is for restaurant 3 and so on 
		employee employee1(20000, "aslam@gmail.com", "Aslam Ahmad", "ALLah10%");
		employee employee2(30000, "arham@gmail.com", "Arham Iftikhar", "ALLah10%");
		employee employee3(40000, "yahya@gmail.com", "Yahya Rashid", "ALLah10%");
		employee employee4(50000, "maida@gmail.com", "Maida Iftikhar", "ALLah10%");
		employee deliver1(60000, "ajmal@gmail.com", "Ajmal Ahmad", "ALLah10%");
		employee deliver2(70000, "khurram@gmail.com", "Khurram Iftikhar", "ALLah10%");
		employee deliver3(80000, "ahmad@gmail.com", "Ahmad", "ALLah10%");
		employee deliver4(90000, "arsalan@gmail.com", "Arsalan", "ALLah10%");
		customer cust1(11111, "m", "Mary", "ALLah10%");
		cust.insert(cust1);
		emp.insert(employee1);
		emp.insert(employee2);
		emp.insert(employee3);
		emp.insert(employee4);
		emp.insert(deliver1);
		emp.insert(deliver2);
		emp.insert(deliver3);
		emp.insert(deliver4);
		//only admin already present in the system
		admin single(99999, "maryam.iftikhar2006@gmail.com", "Maryam Iftikhar", "ALLah10%");
		adm.insert(single);
		logged = false;
		start = NULL;
		startt = NULL;
		populate_promotions(startt);
		menu1 = NULL;
		menu2 = NULL;
		menu3 = NULL;
		menu4 = NULL;
		add_dish(menu1, 10000, "Desserts", Dish(10000, "Chocolate Donut", 500, "Dessert"));
		add_dish(menu1, 10000, "Desserts", Dish(10001, "Ice Cream", 300, "Dessert"));
		add_dish(menu1, 10000, "Desserts", Dish(10002, "Croissant", 500, "Dessert"));
		add_dish(menu1, 10000, "Desserts", Dish(10003, "Apple pie", 700, "Dessert"));
		add_dish(menu1, 10000, "Desserts", Dish(10004, "Gulab Jamun", 200, "Dessert"));
		add_dish(menu1, 10000, "Desserts", Dish(10005, "Custard", 270, "Dessert"));
		add_dish(menu1, 10000, "Desserts", Dish(10006, "Fruit Chat", 350, "Dessert"));
		add_dish(menu1, 10000, "Desserts", Dish(10007, "Brownie", 300, "Dessert"));
		add_dish(menu1, 10000, "Desserts", Dish(10008, "Pastries", 210, "Dessert"));

		add_dish(menu2, 10001, "Desi", Dish(10010, "Samosa", 100, "Appetizer"));
		add_dish(menu2, 10001, "Desi", Dish(10021, "Chicken Biryani", 1200, "Main course"));
		add_dish(menu2, 10001, "Desi", Dish(10032, "Seekh Kabab", 500, "Snack"));
		add_dish(menu2, 10001, "Desi", Dish(10043, "Golgappay", 200, "Appetizer"));
		add_dish(menu2, 10001, "Desi", Dish(10054, "Chicken karahi", 900, "Main course"));
		add_dish(menu2, 10001, "Desi", Dish(10065, "Beef karahi", 670, "Main course"));
		add_dish(menu2, 10001, "Desi", Dish(10076, "Mutton karahi", 1000, "Main course"));
		add_dish(menu2, 10001, "Desi", Dish(10087, "Jalebi", 430, "Dessert"));
		add_dish(menu2, 10001, "Desi", Dish(10098, "Aloo Paratha", 210, "Snack"));

		add_dish(menu3, 10002, "Fast Food", Dish(10110, "Cheeseburger", 700, "Main Course"));
		add_dish(menu3, 10002, "Fast Food", Dish(10221, "French Fries", 300, "Snack"));
		add_dish(menu3, 10002, "Fast Food", Dish(10332, "Chicken Nuggets", 400, "Snack"));
		add_dish(menu3, 10002, "Fast Food", Dish(10443, "Pizza", 1200, "Main Course"));
		add_dish(menu3, 10002, "Fast Food", Dish(10554, "Fried Chicken", 800, "Main Course"));
		add_dish(menu3, 10002, "Fast Food", Dish(10665, "Hot Dog", 500, "Snack"));
		add_dish(menu3, 10002, "Fast Food", Dish(10776, "Milkshake", 250, "Beverage"));
		add_dish(menu3, 10002, "Fast Food", Dish(10887, "Chicken Wrap", 600, "Snack"));
		add_dish(menu3, 10002, "Fast Food", Dish(10998, "Coleslaw", 150, "Side Dish"));
		add_dish(menu3, 10002, "Fast Food", Dish(10999, "Panini", 350, "Snack"));

		add_dish(menu4, 10003, "Chinese", Dish(10012, "Chicken Chowmein", 800, "Main Course"));
		add_dish(menu4, 10003, "Chinese", Dish(10023, "Beef Fried Rice", 700, "Main Course"));
		add_dish(menu4, 10003, "Chinese", Dish(10034, "Hot and Sour Soup", 400, "Appetizer"));
		add_dish(menu4, 10003, "Chinese", Dish(10045, "Spring Rolls", 300, "Snack"));
		add_dish(menu4, 10003, "Chinese", Dish(10056, "Sweet and Sour Chicken", 900, "Main Course"));
		add_dish(menu4, 10003, "Chinese", Dish(10067, "Manchurian", 850, "Main Course"));
		add_dish(menu4, 10003, "Chinese", Dish(10078, "Dim Sum", 600, "Appetizer"));
		add_dish(menu4, 10003, "Chinese", Dish(10089, "Prawn Tempura", 1000, "Snack"));
		add_dish(menu4, 10003, "Chinese", Dish(10091, "Chinese Tea", 150, "Beverage"));
		add_dish(menu4, 10003, "Chinese", Dish(10092, "Ramen", 1150, "Main Course"));

		add_restaurant(start, restaurant(11111, "Sweet & Sour", "Bakery", menu1, &employee1,&deliver1,0));
		add_restaurant(start, restaurant(11112, "Butt Karahi", "Desi Food", menu2, &employee2,&deliver2,1));
		add_restaurant(start, restaurant(11113, "Fast Foodies", "Fast Food", menu3, &employee3,&deliver3,2));
		add_restaurant(start, restaurant(11114, "Golden Dragon", "Chinese Food", menu4, &employee4, &deliver4,3));

		add_review(gdroot, bdroot, 5, "Very GOOD Quality and taste of Golden Dragons", restaurant(11114, "Golden Dragon", "Chinese Food", menu4, &employee1));
		add_review(gdroot, bdroot, 4, "Excellent Job Butt Karahi walon. The taste is so flovour full and authenticc LOve it", restaurant(11112, "Butt Karahi", "Desi Food", menu2, &employee2));
		add_review(gdroot, bdroot, 2, "Very BAd taste EWWWWWW chinese food of Golden Dragon is not original", restaurant(11114, "Golden Dragon", "Chinese Food", menu4, &employee3));
		add_review(gdroot, bdroot, 1, "Taste was super bad Bakry items were not of good quality,", restaurant(11111, "Sweet & Sour", "Bakery", menu1, &employee4));
		order order1(11000, 0, 2);
		Employees* tem;
		tem = emp.findCustomer(20000);
		order1.emplo = &tem->obj;
		Employees* tem2;
		tem2 = emp.findCustomer(60000);
		order1.delivery_boy = &tem2->obj;
		get_dish_by_id(menu1, 10000, order1.dishes[0]);
		get_dish_by_id(menu1, 10001, order1.dishes[1]);
		get_dish_by_id(menu1, 10002, order1.dishes[2]);
		order1.status = "Completed";
		order1.location_for_order_delivery = 5;
		enqueue_order(&orders, order1);

		order order2(11100, 0, 2);
		Employees* te;
		te = emp.findCustomer(30000);
		order2.emplo = &te->obj;
		Employees* te1;
		te1 = emp.findCustomer(70000);
		order2.delivery_boy = &te1->obj;
		get_dish_by_id(menu2, 10043, order2.dishes[0]);
		get_dish_by_id(menu2, 10032, order2.dishes[1]);
		get_dish_by_id(menu2, 10054, order2.dishes[2]);
		enqueue_order(&orders, order2);

		order order3(11010, 0, 2);
		Employees* temo;
		temo = emp.findCustomer(20000);
		order3.emplo = &temo->obj;
		tem2 = emp.findCustomer(60000);
		order3.delivery_boy = &tem2->obj;
		get_dish_by_id(menu1, 10000, order3.dishes[0]);
		get_dish_by_id(menu1, 10007, order3.dishes[1]);
		get_dish_by_id(menu1, 10009, order3.dishes[2]);
		order3.status = "Completed";
		order3.location_for_order_delivery = 10;
		enqueue_order(&orders, order3);
		

		order order4(11110, 0, 2);
		Employees* temu;
		temu = emp.findCustomer(30000);
		order4.emplo = &temu->obj;
		te1 = emp.findCustomer(70000);
		order4.delivery_boy = &te1->obj;
		get_dish_by_id(menu2, 10087, order4.dishes[0]);
		get_dish_by_id(menu2, 10076, order4.dishes[1]);
		get_dish_by_id(menu2, 10065, order4.dishes[2]);
		order4.status = "Completed";
		enqueue_order(&orders, order4);
		
	}
	void mainMenu() {
		int option;
		
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "\033[31m";
			cout << "                       Welcome to Restaurant HUB" << endl;
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~<< MENU >>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Customer                                  [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Admin                                     [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Employee                                  [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Driver                                    [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                      [5]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "Option: ";
			cout << "\033[0m";
			cin >> option;
			//error prevention
			if (cin.fail() || option < 1 || option > 5) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input! Please enter a number between 1 and 4." << endl;
				mainMenu();
			}
			switch (option)
			{
			case 1:
			{
				customerMenu();
				break;
			}
			case 2:
			{
				adminMenu();
				break;
			}
			case 3:
			{
				employeeMenu();
				break;
			}
			case 4:
			{
				driverMenu();
				break;
			}
			case 5:
			{
				exit(0);
			}
			default:
			{
				cout << "Invalid Option! Try Again! Choose some other opwtion" << endl << endl;;
				break;
			}
			}

	}
	void customerMenu() {
		int regularoption;
		do {
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Customer VIEW >>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[37m";;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Login                                     [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               SIGN UP                                   [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Main Menu                                 [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Logout                                    [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                      [5]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "Option: ";
			cout << "\033[0m";
			cin >> regularoption;
		} while (regularoption > 5 || regularoption < 1);
		switch (regularoption) {
		case 1:
			if (logged == false)
			{
				cust.login();
				logged = true;
				cout << "               Enter any number to continue ";
				int num = 0;
				cin >> num;
				subcustomerMenu();
			}
			else {
				cust.login();
				logged = true;
				cout << "               Enter any number to continue ";
				int num = 0;
				cin >> num;
				subcustomerMenu();
			}
			break;
		case 2:
		{
			cust.signUp();
			int in = 0;
			cout << "                   Enter 1 to continue" << endl;
			cin >> in;
			logged = true;
			customerMenu();
			break;
		}
		case 3:
			mainMenu();
			break;
		case 4:
			logged = false;
			customerMenu();
			break;
		case 5:
			exit(0);
			break;

		}
	}
	void subcustomerMenu() {
		int regularoption;
		do {
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Sub Customer Menu >>~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << " \033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Main Menu                                 [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Reset Password                            [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View all Restaurants and their Menu       [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View Menu of a particular Restaurant      [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Logout                                    [5]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                      [6]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View All Promotions                       [7]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Add review                                [8]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View Top 5 good and bad reviews           [9]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                Add Order                                [10]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View Your Order                          [11]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                Complete Order                           [12]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "               Delete Review                             [13]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "               Edit Review                               [14]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "Option: ";
			cout << "\033[0m";
			cin >> regularoption;
		} while (regularoption > 14 || regularoption < 1);

		switch (regularoption) {
		case 1:
		{
			mainMenu();
			break;
		}
		case 2:
		{
			cust.reset_name_pass();
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 3:
		{
			display_restaurants(start);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 4:
		{int opt = 0;
		do
		{
			system("cls");
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "\033[34m";
			cout << "                            Restaurants" << endl;
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                   Sweet & Sour                          [1]" << endl;
			cout << "                   Butt Karahi                           [2]" << endl;
			cout << "                   Fast Foodies                          [3]" << endl;
			cout << "                   Golden Dragon                         [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                 Enter option :"; cout << "\033[0m"; cin >> opt;

		} while (opt < 1 || opt>4);
		switch (opt) {
		case 1:
		{
			display_menu(menu1);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 2:
		{
			display_menu(menu2);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 3:
		{
			display_menu(menu3);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 4:
		{
			display_menu(menu4);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		}
		break;
		}
		case 5:
		{
			logged = false;
			customerMenu();
			break;
		}
		case 6:
		{
			exit(0);
			break;
		}
		case 7:
		{
			view_promotions(startt);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 8:
		{//add_review(Reviews_good*& gdRoot, Reviews_bad*& bdRoot, int rate, string desc, const restaurant& res)
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "                  Enter rating out of 5";
			int rat = 0;
			cin >> rat; string decs = "";
			cout << "                   Enter your review ";
			cin.ignore();
			getline(cin, decs);
			cout << " Enter 1 if your review is for restaurant /Sweet & Sour/ 2 for /Butt Karahi/ 3 for /Golden Dragon/ and 4 for /Fast Foodies/" << endl;
			int op = 0;
			do
			{
				cin >> op;
				if (op == 1)
					add_review(gdroot, bdroot, rat, decs, restaurant(11111, "Sweet & Sour", "Bakery", menu1));
				else if (op == 2)
					add_review(gdroot, bdroot, rat, decs, restaurant(11112, "Butt Karahi", "Desi Food", menu2));
				else if (op == 3)
					add_review(gdroot, bdroot, rat, decs, restaurant(11114, "Golden Dragon", "Chinese Food", menu4));
				else if (op == 4)
					add_review(gdroot, bdroot, rat, decs, restaurant(11113, "Fast Foodies", "Fast Food", menu3));
			} while (op < 1 || op>4);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 9:
		{
			display_top_5_bad_and_good_reviews(gdroot, bdroot);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 10:
		{int typ = 1;
		Employees* temp,*driv;
		system("cls");
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~Adding your order~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		do {
			cout << "        Enter order type (1:Normal) (2:Express) (3:Premium) ";
			cin >> typ;
		} while (typ < 1 || typ>3);
		order your_order(generate_id(), 0, typ);
		int lo = 0;
		cout << "               Choose your location " << endl;
		cout << "Enter 0 for F-12, 1 for G-12, 2 for G-8, 3 for F-9, 4 for G-6, 5 for H-8, 6 for F-11, 7 for F-5,\n"
			<< "8 for I-11, 9 for H-11, 10 for I-15, 11 for I-12, 12 for I-14, 13 for I-16, 14 for F-7,\n"
			<< "15 for I-9, 16 for F-6, 17 for H-10, 18 for G-14, 19 for H-9, 20 for I-8, 21 for G-10,\n"
			<< "22 for G-9, 23 for F-10, 24 for F-8, 25 for G-11, 26 for I-10, 27 for H-9,28 for G-7,29 for G-5.\n";
		cin >> lo;
		your_order.location_for_order_delivery = lo;
		do {
			cout << "          Choose Restaurant 1:Sweet & Sour 2:Butt Karahi 3:Fast Foodies 4: Golden Dragon" << endl;
			cin >> typ;
		} while (typ < 1 || typ>4);
		if (typ == 1) {
			driv = emp.findCustomer(60000);
			your_order.delivery_boy = &driv->obj;
			temp = emp.findCustomer(20000);
			your_order.emplo = &temp->obj;
			cout << "Enter the number of dishes you want to place in your order" << endl;
			cin >> typ;
			for (int i = 0; i < typ; i++) {
				int na = 0;
				cout << "Enter id of the dish" << endl;
				cin >> na;
				get_dish_by_id(menu1, na, your_order.dishes[i]);
			}
		}
		else if (typ == 2) {
			driv = emp.findCustomer(70000);
			your_order.delivery_boy = &driv->obj;
			temp = emp.findCustomer(30000);
			your_order.emplo = &temp->obj;
			cout << "Enter the number of dishes you want to place in your order" << endl;
			cin >> typ;
			for (int i = 0; i < typ; i++) {
				int na = 0;
				cin >> na;
				cout << "Enter id of the dish" << endl;
				get_dish_by_id(menu1, na, your_order.dishes[i]);
			}
		}
		else if (typ == 3) {
			driv = emp.findCustomer(80000);
			your_order.delivery_boy = &driv->obj;
			temp = emp.findCustomer(40000);
			your_order.emplo = &temp->obj;
			cout << "Enter the number of dishes you want to place in your order" << endl;
			cin >> typ;
			for (int i = 0; i < typ; i++) {
				int na = 0;
				cout << "Enter id of the dish" << endl;
				cin >> na;
				get_dish_by_id(menu1, na, your_order.dishes[i]);
			}
		}
		else if (typ == 4) {
			driv = emp.findCustomer(90000);
			your_order.delivery_boy = &driv->obj;
			temp = emp.findCustomer(50000);
			your_order.emplo = &temp->obj;
			cout << "Enter the number of dishes you want to place in your order" << endl;
			cin >> typ;
			for (int i = 0; i < typ; i++) {
				int na = 0;
				cout << "Enter id of the dish" << endl;
				cin >> na;
				get_dish_by_id(menu1, na, your_order.dishes[i]);
			}
		}
		enqueue_order(&orders, your_order);
		cout << "Your Order ID " << your_order.id << " added successfully!" << endl;
		string y;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Enter yes to go back to sub customer menu " << endl;
		cin >> y;
		if (y == "yes" || y == "Yes")
			subcustomerMenu();
		break;
		}
		case 11:
		{
			int yourorderid = 0;
			cout << " Enter your order id " << endl;
			cin >> yourorderid;
			display_particular_order(&orders, yourorderid);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 12:
		{
			int yourorderid = 0;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                    Enter your order id ";
			cin >> yourorderid;
			complete_order(&orders, yourorderid, startt);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 13:
		{
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                    Enter your review id ";
			int rev_id = 0;
			cin >> rev_id;
			delete_review(gdroot, rev_id);
			delete_review(bdroot, rev_id);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subcustomerMenu();
			break;
		}
		case 14:
		{cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "                    Enter your review id ";
		int rev_id = 0;
		cin >> rev_id;
		edit_review(gdroot, bdroot, rev_id);
		string y;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Enter yes to go back to sub customer menu " << endl;
		cin >> y;
		if (y == "yes" || y == "Yes")
			subcustomerMenu();
		break;
		}
		}
	}
	void employeeMenu() {
		int regularoption;
		do {
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Employee VIEW >>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[37m";;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Login                                     [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Main Menu                                 [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Logout                                    [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                      [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "Option: ";
			cout << "\033[0m";
			cin >> regularoption;
		} while (regularoption > 4 || regularoption < 1);
		switch (regularoption) {
		case 1:
			if (logged == false)
			{
				emp.login();
				logged = true;
				cout << "               Enter any number to continue ";
				int num = 0;
				cin >> num;
				subemployeeMenu();
			}
			else {
				emp.login();
				logged = true;
				cout << "               Enter any number to continue ";
				int num = 0;
				cin >> num;
				subemployeeMenu();
			}
			break;
		case 2:
		{
			mainMenu();
			break;
		}
		case 3:
			logged = false;
			employeeMenu();
			break;
		case 4:
			exit(0);
			break;
		}
	}
	void adminMenu() {
		int regularoption;
		do {
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Admin VIEW >>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[37m";;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Login                                     [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Main Menu                                 [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Logout                                    [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                      [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "Option: ";
			cout << "\033[0m";
			cin >> regularoption;
		} while (regularoption > 4 || regularoption < 1);
		switch (regularoption) {
		case 1:
			if (logged == false)
			{
				adm.login();
				logged = true;
				subadminMenu();
			}
			else {
				adm.login();
				logged = true;
				subadminMenu();
			}
			break;
		case 2:
		{
			mainMenu();
			break;
		}
		case 3:
			logged = false;
			adminMenu();
			break;
		case 4:
			exit(0);
			break;
		}
	}
	void subemployeeMenu() {
		int regularoption;
		do {
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Sub Employee Menu >>~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << " \033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Main Menu                                       [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Reset Password                                  [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View all Restaurants and their Menu             [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View Menu of a particular Restaurant            [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Logout                                          [5]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                            [6]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View All Promotions                             [7]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "              View Top 5 good and bad reviews of all restaurants [8]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View all processed orders                       [9]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View all Orders of your restaurant              [10]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                View current order and its status               [11]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "Option: ";
			cout << "\033[0m";
			//order will automatically be processed by you when the customer completes the order
			cin >> regularoption;
		} while (regularoption > 11 || regularoption < 1);
		switch (regularoption) {
		case 1:
		{
			mainMenu();
			break;
		}
		case 2:
		{
			emp.reset_name_pass();
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub employee menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		case 3:
		{
			display_restaurants(start);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub customer menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		case 4:
		{int opt = 0;
		do
		{
			system("cls");
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "\033[34m";
			cout << "                            Restaurants" << endl;
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                   Sweet & Sour                          [1]" << endl;
			cout << "                   Butt Karahi                           [2]" << endl;
			cout << "                   Fast Foodies                          [3]" << endl;
			cout << "                   Golden Dragon                         [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                 Enter option :"; cout << "\033[0m"; cin >> opt;

		} while (opt < 1 || opt>4);
		switch (opt) {
		case 1:
		{
			display_menu(menu1);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub employee menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		case 2:
		{
			display_menu(menu2);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub employee menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		case 3:
		{
			display_menu(menu3);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub employee menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		case 4:
		{
			display_menu(menu4);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub employee menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		}
		break;
		}
		case 5:
		{
			logged = false;
			employeeMenu();
			break;
		}
		case 6:
		{
			exit(0);
			break;
		}
		case 7:
		{
			view_promotions(startt);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub employee menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		case 8:
		{
			display_top_5_bad_and_good_reviews(gdroot, bdroot);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub employee menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		case 9:
		{int emp_id = 0;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Dear Employee , please enter your id to view" << endl;
		cout << "                         all orders processed by you"; cin >> emp_id;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		display_particular_restaurant_processed_order(&orders, emp_id);
		string y;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Enter yes to go back to sub employee menu " << endl;
		cin >> y;
		if (y == "yes" || y == "Yes")
			subemployeeMenu();
		break;
		}
		case 10:
		{
			int emp_id = 0;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Dear Employee , please enter your id to view" << endl;
			cout << "                         all orders of your restaurant"; cin >> emp_id;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			display_particular_restaurant_order(&orders, emp_id);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub employee menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subemployeeMenu();
			break;
		}
		case 11:
		{int emp_id = 0;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Dear Employee , please enter your id to view" << endl;
		cout << "                         current order of restaurant"; cin >> emp_id;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		display_particular_restaurant_current_order(&orders, emp_id);
		string y;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Enter yes to go back to sub employee menu " << endl;
		cin >> y;
		if (y == "yes" || y == "Yes")
			subemployeeMenu();
		break;
		}
		}
	}
	void subadminMenu() {
		int regularoption;
		do {
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Sub Admin Menu >>~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << " \033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Main Menu                                       [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Reset Password                                  [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View all Restaurants and their Menu             [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View Menu of a particular Restaurant            [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Logout                                          [5]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                            [6]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View All promotions                             [7]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "              View Top 5 good and bad reviews of all restaurants [8]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View all processed orders                       [9]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View all Orders of all restaurant              [10]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "               Add Promotion                                   [11]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "               Delete Promotion                                [12]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "               Add dish to a restaurant                        [13]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "               Delete dish of a restaurant                     [14]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "               Edit  dish of a restaurant                      [15]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			//add restaurant and delete restaurant, edit function is present but for user simplicity it has not been displayed
			cout << "Option: ";
			cout << "\033[0m";
			//order will automatically be processed by you when the customer completes the order
			cin >> regularoption;
		} while (regularoption > 15 || regularoption < 1);
		switch (regularoption) {
		case 1:
		{
			mainMenu();
			break;
		}
		case 2:
		{
			adm.reset_name_pass();
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 3:
		{
			display_restaurants(start);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 4:
		{int opt = 0;
		do
		{
			system("cls");
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "\033[34m";
			cout << "                            Restaurants" << endl;
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                   Sweet & Sour                          [1]" << endl;
			cout << "                   Butt Karahi                           [2]" << endl;
			cout << "                   Fast Foodies                          [3]" << endl;
			cout << "                   Golden Dragon                         [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                 Enter option :"; cout << "\033[0m"; cin >> opt;

		} while (opt < 1 || opt>4);
		switch (opt) {
		case 1:
		{
			display_menu(menu1);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 2:
		{
			display_menu(menu2);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 3:
		{
			display_menu(menu3);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 4:
		{
			display_menu(menu4);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		}
		break;
		}
		case 5:
		{
			logged = false;
			adminMenu();
			break;
		}
		case 6:
		{
			exit(0);
			break;
		}
		case 7:
		{
			view_promotions(startt);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 8:
		{
			display_top_5_bad_and_good_reviews(gdroot, bdroot);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 9:
		{
			display_particular_restaurant_processed_order(&orders, 20000);
			display_particular_restaurant_processed_order(&orders, 30000);
			display_particular_restaurant_processed_order(&orders, 40000);
			display_particular_restaurant_processed_order(&orders, 50000);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 10:
		{
			display_order(&orders);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 11:
		{
			string promname = "";
			double dis = 0;
			int num_order = 0;
			system("cls");
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~Adding Promotion~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter name of the promotion"; cin.ignore();
			getline(cin, promname);
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter the discount"; cin >> dis;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "              Enter the max number of orders on which it can be applied"; cin >> num_order;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			promotion newpromotion(generate_id(), promname, dis, num_order);
			promotion_push(startt, newpromotion);
			cout << "                  Promtion " << promname << " successfully added" << endl;
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 12:
		{
			delete_promotion(startt);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 13:
		{
			//add_dish(menu1, 10000, "Desserts", Dish(10000, "Chocolate Donut", 500, "Dessert"));
			string promname = "";
			double dis = 0;
			string num_order = "";
			system("cls");
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~Adding Dish~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter name of the dish"; cin.ignore();
			getline(cin, promname);
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter the price"; cin >> dis;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "              Enter dish type such as dessert "; cin.ignore();
			getline(cin, num_order);
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			int opt = 0;
			do
			{
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
				cout << "                Choose Restaurant where you want to place this dish" << endl;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
				cout << "                   Sweet & Sour                          [1]" << endl;
				cout << "                   Butt Karahi                           [2]" << endl;
				cout << "                   Fast Foodies                          [3]" << endl;
				cout << "                   Golden Dragon                         [4]" << endl;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
				cout << "                 Enter option :"; cout << "\033[0m"; cin >> opt;

			} while (opt < 1 || opt>4);
			switch (opt) {
			case 1: {
				add_dish(menu1, 10000, "Desserts", Dish(generate_id(), promname, dis, num_order));
				cout << "                Dish Added successfully" << endl;
				string y;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
				cout << "               Enter yes to go back to sub admin menu " << endl;
				cin >> y;
				if (y == "yes" || y == "Yes")
					subadminMenu();
				break;
			}
			case 2: {
				add_dish(menu2, 10001, "Desi", Dish(generate_id(), promname, dis, num_order));
				cout << "                Dish Added successfully" << endl;
				string y;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
				cout << "               Enter yes to go back to sub admin menu " << endl;
				cin >> y;
				if (y == "yes" || y == "Yes")
					subadminMenu();
				break;
			}
			case 3: {
				add_dish(menu3, 10002, "Fast Food", Dish(generate_id(), promname, dis, num_order));
				cout << "                Dish Added successfully" << endl;
				string y;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
				cout << "               Enter yes to go back to sub admin menu " << endl;
				cin >> y;
				if (y == "yes" || y == "Yes")
					subadminMenu();
				break;
			}
			case 4: {
				add_dish(menu4, 10003, "Chinese", Dish(generate_id(), promname, dis, num_order));
				cout << "                Dish Added successfully" << endl;
				string y;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
				cout << "               Enter yes to go back to sub admin menu " << endl;
				cin >> y;
				if (y == "yes" || y == "Yes")
					subadminMenu();
				break;
			}
			}
			break;
		}
		case 14:
		{
			//Menu* delete_dish(Menu*& root, int idd)

			int opt = 0;
			do
			{
				cout << "\033[37m";
				system("cls");
				cout << "\033[34m";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Deleting Dish~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
				cout << "                Choose Restaurant whose dish you want to delete" << endl;
				cout << "\033[37m";
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
				cout << "                   Sweet & Sour                          [1]" << endl;
				cout << "                   Butt Karahi                           [2]" << endl;
				cout << "                   Fast Foodies                          [3]" << endl;
				cout << "                   Golden Dragon                         [4]" << endl;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
				cout << "                 Enter option :"; cout << "\033[0m"; cin >> opt;

			} while (opt < 1 || opt>4);
			switch (opt) {
			case 1:
			{
				cout << "Enter dish id " << endl;
				int dish_idd = 0;
				cin >> dish_idd;
				delete_dish(menu1, dish_idd);
				string y;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
				cout << "               Enter yes to go back to sub admin menu " << endl;
				cin >> y;
				if (y == "yes" || y == "Yes")
					subadminMenu();
				break;
			}
			case 2:
			{
				cout << "Enter dish id " << endl;
				int dish_idd = 0;
				cin >> dish_idd;
				delete_dish(menu2, dish_idd);
				string y;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
				cout << "               Enter yes to go back to sub admin menu " << endl;
				cin >> y;
				if (y == "yes" || y == "Yes")
					subadminMenu();
				break;
			}
			case 3:
			{
				cout << "Enter dish id " << endl;
				int dish_idd = 0;
				cin >> dish_idd;
				delete_dish(menu3, dish_idd);
				string y;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
				cout << "               Enter yes to go back to sub admin menu " << endl;
				cin >> y;
				if (y == "yes" || y == "Yes")
					subadminMenu();
				break;
			}
			case 4:
			{
				cout << "Enter dish id " << endl;
				int dish_idd = 0;
				cin >> dish_idd;
				delete_dish(menu4, dish_idd);
				string y;
				cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
				cout << "               Enter yes to go back to sub admin menu " << endl;
				cin >> y;
				if (y == "yes" || y == "Yes")
					subadminMenu();
				break;
			}
			}
			break;
		}
		case 15:
		{int opt = 0;
		do
		{
			cout << "\033[37m";
			system("cls");
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Editing Dish~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                Choose Restaurant whose dish you want to edit" << endl;
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                   Sweet & Sour                          [1]" << endl;
			cout << "                   Butt Karahi                           [2]" << endl;
			cout << "                   Fast Foodies                          [3]" << endl;
			cout << "                   Golden Dragon                         [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                 Enter option :"; cout << "\033[0m"; cin >> opt;

		} while (opt < 1 || opt>4);
		switch (opt) {
		case 1:
		{
			cout << "Enter dish id " << endl;
			int dish_idd = 0;
			cin >> dish_idd;
			edit_dish(menu1, dish_idd);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 2:
		{
			cout << "Enter dish id " << endl;
			int dish_idd = 0;
			cin >> dish_idd;
			edit_dish(menu2, dish_idd);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 3:
		{
			cout << "Enter dish id " << endl;
			int dish_idd = 0;
			cin >> dish_idd;
			edit_dish(menu3, dish_idd);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		case 4:
		{
			cout << "Enter dish id " << endl;
			int dish_idd = 0;
			cin >> dish_idd;
			edit_dish(menu4, dish_idd);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub admin menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subadminMenu();
			break;
		}
		}
		break;
		}
		}
	}
	void driverMenu() {
		int regularoption;
		do {
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Delivery Man VIEW >>~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[37m";;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Login                                     [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Main Menu                                 [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Logout                                    [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                      [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "Option: ";
			cout << "\033[0m";
			cin >> regularoption;
		} while (regularoption > 4 || regularoption < 1);
		switch (regularoption) {
		case 1:
			if (logged == false)
			{
				emp.login();
				logged = true;
				cout << "               Enter any number to continue ";
				int num = 0;
				cin >> num;
				subdriverMenu();
			}
			else {
				emp.login();
				logged = true;
				cout << "               Enter any number to continue ";
				int num = 0;
				cin >> num;
				subdriverMenu();
			}
			break;
		case 2:
		{
			mainMenu();
			break;
		}
		case 3:
			logged = false;
			driverMenu();
			break;
		case 4:
			exit(0);
			break;
		}
	}
	void subdriverMenu(){
		int regularoption;
		do {
			system("cls");
			cout << "\033[37m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << "\033[34m";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~<< Sub Driver Menu >>~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
			cout << " \033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Main Menu                                       [1]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Reset Password                                  [2]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View all Restaurants and their Menu             [3]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               View Menu of a particular Restaurant            [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Logout                                          [5]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Exit                                            [6]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View All Promotions                             [7]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "              View Top 5 good and bad reviews of all restaurants [8]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View all paths of processed orders               [9]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "                View all Orders of your restaurant              [10]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                View current order and its status               [11]               " << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "Option: ";
			cout << "\033[0m";
			//order will automatically be processed by you when the customer completes the order
			cin >> regularoption;
		} while (regularoption > 11 || regularoption < 1);
		switch (regularoption) {
		case 1:
		{
			mainMenu();
			break;
		}
		case 2:
		{
			emp.reset_name_pass();
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		case 3:
		{
			display_restaurants(start);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		case 4:
		{int opt = 0;
		do
		{
			system("cls");
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "\033[34m";
			cout << "                            Restaurants" << endl;
			cout << "\033[37m";
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                   Sweet & Sour                          [1]" << endl;
			cout << "                   Butt Karahi                           [2]" << endl;
			cout << "                   Fast Foodies                          [3]" << endl;
			cout << "                   Golden Dragon                         [4]" << endl;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~              " << endl;
			cout << "                 Enter option :"; cout << "\033[0m"; cin >> opt;

		} while (opt < 1 || opt>4);
		switch (opt) {
		case 1:
		{
			display_menu(menu1);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		case 2:
		{
			display_menu(menu2);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		case 3:
		{
			display_menu(menu3);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		case 4:
		{
			display_menu(menu4);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		}
		break;
		}
		case 5:
		{
			logged = false;
			driverMenu();
			break;
		}
		case 6:
		{
			exit(0);
			break;
		}
		case 7:
		{
			view_promotions(startt);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		case 8:
		{
			display_top_5_bad_and_good_reviews(gdroot, bdroot);
			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		case 9:
		{int emp_id = 0;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Dear driver , please enter your id to view" << endl;
		cout << "                         all orders processed by you"; cin >> emp_id;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		display_particular_restaurant_processed_order_delivery(&orders, emp_id);
		string y;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Enter yes to go back to sub driver menu " << endl;
		cin >> y;
		if (y == "yes" || y == "Yes")
			subdriverMenu();
		break;
		}
		case 10:
		{
			int emp_id = 0;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Dear driver , please enter your id to view" << endl;
			cout << "                         all orders of your restaurant"; cin >> emp_id;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			display_particular_restaurant_order_delivery(&orders, emp_id);

			string y;
			cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
			cout << "               Enter yes to go back to sub driver menu " << endl;
			cin >> y;
			if (y == "yes" || y == "Yes")
				subdriverMenu();
			break;
		}
		case 11:
		{int emp_id = 0;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Dear driver , please enter your id to view" << endl;
		cout << "                         current order of restaurant"; cin >> emp_id;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		display_particular_restaurant_current_order_delivery(&orders, emp_id);
		string y;
		cout << "              ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               " << endl;
		cout << "               Enter yes to go back to sub driver menu " << endl;
		cin >> y;
		if (y == "yes" || y == "Yes")
			subdriverMenu();
		break;
		}
		}
	}
};

int main() {
	Menu_for_main obj;
	obj.mainMenu();
	return 0;
}
