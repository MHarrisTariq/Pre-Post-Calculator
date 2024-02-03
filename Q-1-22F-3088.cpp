//#include<iostream>
//#include<string>
//#include<conio.h>//for getch
//using namespace std;
//class myStack {
//public:
//	//its the node structure.
//	struct node {
//		string data;
//		node* next;
//		node(string value) {
//			data = value;
//			next = NULL;
//		}
//	};
//	//variabe
//	node* top;
//	int size = -1;
//	//constructor
//	myStack()
//	{
//		top = NULL;
//	}
//	//for push the elements
//	void push(string value) {
//		node* n = new node(value);
//		if (isEmpty()) {
//			top = n;
//		}
//		else {
//
//			n->next = top;
//			top = n;
//		}
//		size += 1;
//	}
//	//for ppop the elemets from the stack
//	string pop()
//	{
//		if (size == -1) {
//			cout << "WE CAN NOT POP THE STACK ,COZ THE STCAK IS EMPTY ! \n";
//			return "";
//		}
//		{
//			string value = top->data;
//			node* temp = top;
//			top = top->next;
//			delete temp;
//			size = size - 1;
//			return value;
//		}
//	}
//	//empty checl
//	bool isEmpty()
//	{
//		return size == -1;
//	}
//	//to check which element on the stack without removng it
//	string currentElementOnStack() {
//		if (isEmpty()) {
//			cout << "Stack is empty." << endl;
//			return ""; // Return an empty string or handle the error
//		}
//		string value = top->data;
//		return value;
//	}
//	//to display stack
//	void stackDisplay() {
//		if (isEmpty()) {
//			cout << "HRS Stack Empty";
//			return;
//		}
//		myStack tempStack; // Temporary stack so our orignal data not lost
//		cout << "Stack: ";
//		while (!isEmpty()) {
//			string value = pop();
//			cout << value << " ";
//			tempStack.push(value);
//		}
//		// Push elements back to the original stack
//		while (!tempStack.isEmpty()) {
//			push(tempStack.pop());
//		}
//	}
//};
////side functions
////check the precedence is high or equal
//bool checkPrecedence(string currentOn, string onRunning) {
//
//	//1  ((,(*,(/,(%,(+,(-
//	//2  *(,**,*/,*%,*+,*-
//	//3  /(,/*,//,/%,/+,/-
//	//4  %(,%*,%/,%%,%+,%-
//	//5  +(,+*,+/,+%,++,+-
//	//6  -(,-*,-/,-%,-+,--
//
//	if (currentOn == "(") { //code#1
//		return true;
//	}
//	if (currentOn == onRunning) {//code #2
//		return true;
//	}
//	//r2
//	if ((currentOn == "*" && onRunning == "(") || (currentOn == "*" && onRunning == "/") || (currentOn == "*" && onRunning == "%")) {//r2
//		return true;
//	}
//	if ((currentOn == "*" && onRunning == "+") || (currentOn == "*" && onRunning == "-")) {//r2
//		return false;
//	}
//	//r3
//	if ((currentOn == "/" && onRunning == "(") || (currentOn == "/" && onRunning == "*") || (currentOn == "/" && onRunning == "%")) {
//		return true;
//	}
//	if ((currentOn == "/" && onRunning == "+") || (currentOn == "/" && onRunning == "-")) {
//		return false;
//	}
//	//r4
//	if ((currentOn == "%" && onRunning == "(") || (currentOn == "%" && onRunning == "*") || (currentOn == "%" && onRunning == "/")) {
//		return true;
//	}
//	if ((currentOn == "%" && onRunning == "+") || (currentOn == "%" && onRunning == "-")) {
//		return false;
//	}
//	//r5
//	if ((currentOn == "+" && onRunning == "(") || (currentOn == "+" && onRunning == "*") || (currentOn == "+" && onRunning == "/") || (currentOn == "+" && onRunning == "%")) {
//		return true;
//	}
//	if ((currentOn == "+" && onRunning == "-")) {
//		return false;
//	}
//	//r5
//	if ((currentOn == "-" && onRunning == "(") || (currentOn == "-" && onRunning == "*") || (currentOn == "-" && onRunning == "/") || (currentOn == "-" && onRunning == "%") || (currentOn == "-" && onRunning == "+")) {
//		return true;
//	}
//
//}
////function to remove the white spaces means blank spaces.
//string removeSpaces(const string& input) {
//	string result;
//	for (char c : input) {
//		if (!std::isspace(c)) {
//			result += c;
//		}
//	}
//	return result;
//}
////function to make postfix expression
//string makePostFix(string expression) {
//	cout << "----------------------------------------------------------------------------------------------\n";
//	cout << "HEHE FUNCTION WORKING---->\n";
//	cout << "GIVEN EXPRESSION IS: " << expression << endl;
//	cout << "----------------------------------------------------------------------------------------------\n";
//	int lengthOfExpression = expression.length();
//	string postFixExpressionString = "";
//	myStack temp;
//	myStack hrs;
//	for (int i = 0; i < lengthOfExpression; i++)
//	{
//		cout << "INPUT: " << expression[i] << "\t\t";
//		temp.stackDisplay();
//		cout << "\t\t";
//		if (expression[i] == '(' || expression[i] == ')' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%' || expression[i] == '+' || expression[i] == '-')
//		{
//			if (temp.isEmpty()) {
//
//				string str = string() + expression[i];
//				temp.push(str);
//
//			}
//			else {
//				string str = string() + expression[i];
//				string current = temp.currentElementOnStack();
//
//				if (str == ")") {
//
//					string t = temp.pop();
//
//					while (t != "(") {
//
//						postFixExpressionString += t;
//						postFixExpressionString += " ";
//						t = temp.pop();
//					}
//				}
//				else {
//
//					if (checkPrecedence(current, str)) {
//						temp.push(str);
//					}
//					else {
//						postFixExpressionString += temp.pop();
//						postFixExpressionString += " ";
//						temp.push(str);
//					}
//				}
//			}
//		}
//		else {
//
//			postFixExpressionString += expression[i];
//			if ((i + 1) < expression.length() && (expression[i + 1] == '(' || expression[i + 1] == ')' || expression[i + 1] == '*' || expression[i + 1] == '/' || expression[i + 1] == '%' || expression[i + 1] == '+' || expression[i + 1] == '-')) {
//				postFixExpressionString +=" ";
//			}
//		}
//		cout << "Current Expression: " << postFixExpressionString << endl; // Display current expression
//	}
//	// Pop remaining elements from the stack and append to the postfix expression
//	postFixExpressionString += " ";
//	while (!temp.isEmpty()) {
//		postFixExpressionString += temp.pop();
//		postFixExpressionString += " ";
//	}
//	cout << "----------------------------------------------------------------------------------------------\n";
//	cout << "FINAL EXPRESSION: " << postFixExpressionString << endl;
//	cout << "----------------------------------------------------------------------------------------------\n";
//	return postFixExpressionString;
//}
////this functon solve that postfix or infix expression
//string polishNotationHRS(string expression) {
//	myStack temp;
//	int lengthOfExpression = expression.length();
//	string myString = "";
//	for (int i = 0; i < lengthOfExpression; i++)
//	{
//		if (expression[i] == ' ') {
//			temp.push(myString);
//			myString = "";
//		}
//		else {
//			string s = string() + expression[i];
//			myString += s;
//		}
//	}
//	//stack ko sedha krny k liye ye kiya hai
//	myStack temp2;
//	while (!temp.isEmpty()) {
//		temp2.push(temp.pop());
//	}
//	//temp2.stackDisplay();
//	//cout << endl << temp2.pop();
//	
//	//ab ham polish notaion k zrye solve krenge expression ko
//	myStack polish;
//	bool con = true;
//	cout << "SOLVING AS A POLISH NOTATION: " << endl;
//	cout << "----------------------------------------------------------------------------------------------\n";
//	while (!temp2.isEmpty())
//	{
//		polish.stackDisplay();
//		cout << endl;
//		string str = temp2.pop();
//		if (str == "*") {
//			int a = stoi(polish.pop());
//			int b = stoi(polish.pop());
//			int c = a * b;
//			polish.push(to_string(c));
//		}else if (str == "/") {
//			int a = stoi(polish.pop());
//			int b = stoi(polish.pop());
//			int c = b / a;
//			polish.push(to_string(c));
//		} else if (str == "%") {
//			int a = stoi(polish.pop());
//			int b = stoi(polish.pop());
//			int c = b % b;
//			polish.push(to_string(c));
//		}else if (str == "+") {
//			int a = stoi(polish.pop());
//			int b = stoi(polish.pop());
//			int c = a + b;
//			polish.push(to_string(c));
//		}else if (str == "-") {
//			int a = stoi(polish.pop());
//			int b = stoi(polish.pop());
//			int c = b - a;
//			polish.push(to_string(c));
//		}
//		else {
//			polish.push(str);
//		}
//	}
//	string last = polish.pop();
//	cout << "----------------------------------------------------------------------------------------------\n";
//	cout << "SOLVED EXPRESSION IS: " <<last<< endl;
//	cout << "----------------------------------------------------------------------------------------------\n";
//	//polish.pop();
//	return last;
//}
////remove double space 
////ye is waja sy kiya keunk double space a rhi the expression ma to jb wo stack ma jata the error deta
//string removeDoubleSpace(string expression) {
//	int len = expression.length();
//	string newString="";
//	for (int i = 0; i < len; i++)
//	{
//		if (expression[i] == ' '&& expression[i+1]==' ') {
//			i++;
//		}
//		string str = string() + expression[i];
//		newString += str;
//	}
//	return newString;
//}
////here we make functions that is necessray for infix to prefix
//string reverseString(const string& str) {
//	int length = str.length();
//	string reversedStr = str;
//
//	for (int i = 0; i < length / 2; ++i) {
//		char temp = reversedStr[i];
//		reversedStr[i] = reversedStr[length - i - 1];
//		reversedStr[length - i - 1] = temp;
//	}
//	return reversedStr;
//}
//string reverseInfix(string expression) {
//	int len = expression.length();
//	string newString = "";
//	myStack temp;
//	for (int i = 0; i < len; i++)
//	{
//		if (expression[i] == ')') {
//
//			expression[i] = '(';
//		}
//		else if (expression[i] == '(') {
//
//			expression[i] = ')';
//		}
//
//		temp.push((string() + expression[i]));
//	}
//	while (!temp.isEmpty()) {
//		newString += temp.pop();
//	}
//	//return newString;
//	//cout<<newString<<endl;
//	//now
//	string myString = "";
//	string intStr = "";
//	bool con = false;
//	for (int i = 0; i < newString.length(); i++)
//	{
//		if (newString[i] != '(' && newString[i] != '*' && newString[i] != '/' && newString[i] != '%' && newString[i] != '+' && newString[i] != '-' && newString[i] != ')') {
//			con = true;
//			intStr += newString[i];
//		}
//		else
//		{
//			if (con == true)
//			{
//				myString += reverseString(intStr);
//				intStr = "";
//				con = false;
//			}
//			else{
//				//myString += newString[i];
//				con = false;
//			}
//			if (newString[i] != '(' || newString[i] != '*' || newString[i] != '/' || newString[i] != '%' || newString[i] != '+' || newString[i] != '-' || newString[i] != ')') {
//				myString += newString[i];
//			}
//		}
//		//
//	}
//	return myString;
//}
//int main()
//{
//	string infixExpression;
//	cout << "----------------------------------------------------------------------------------------------\n";
//	cout <<"WELCOME TO HRS INFIX TO POST-PRE FIX CALCULATOR  :-) "<< endl;
//	cout << "----------------------------------------------------------------------------------------------\n";
//	cout << "An Infix expression may contain positive integers, the five arithmetic operators (+,- , *, / , %)\n";
//	cout << "----------------------------------------------------------------------------------------------\n";
//	cout << "MENU:\n";
//	cout << "PRESS 1 FOR POSTFIX.\n";
//	cout << "PRESS 2 FOR PREFIX.\n";
//	cout << "PRESS 3 TO EXIT. ";
//	cout << "\n----------------------------------------------------------------------------------------------\n";
//	char chr;
//	do {
//		chr=_getch();
//		if (chr != 49 && chr != 50 && chr != 51) {
//			cout << "\nWRONG INPUT\nENTER AGAIN.";
//			//cout << chr << endl;
//		}
//	} while (chr!=49&&chr!=50&&chr!=51);
//	//we use swict for menu program hurray!
//	string postfixExpresssion;
//	string prefixExpresssion;
//	string solvedExression;
//	string reverseExpression;
//
//	switch (chr)
//	{
//	case '1':
//		cout << "\nENTER ANY INFIX EXPRESSION:";
//		getline(cin, infixExpression);
//		cout << "THE EXPRESSION YOU ENTERED IS:  " << infixExpression << endl;
//		infixExpression = removeSpaces(infixExpression); //remove the space from the infix expression.
//		postfixExpresssion=makePostFix(infixExpression);
//	    postfixExpresssion=removeDoubleSpace(postfixExpresssion);
//		solvedExression = polishNotationHRS(postfixExpresssion);
//		break;
//	case '2':
//		cout << "\nENTER ANY INFIX EXPRESSION:";
//		getline(cin, infixExpression);
//		cout << "THE EXPRESSION YOU ENTERED IS:  " << infixExpression << endl;
//		infixExpression = removeSpaces(infixExpression); //remove the space from the infix expression.
//		//now reverse
//		reverseExpression = reverseInfix(infixExpression);//1s step reverse
//		prefixExpresssion = makePostFix(reverseExpression);//2nd solve as postfix
//		//cout << "reverseExpression: through main :" << reverseExpression << endl;
//		//cout << "through main :" << prefixExpresssion << endl;
//		//prefixExpresssion = reverseInfix(prefixExpresssion);// 3rd 
//		prefixExpresssion = removeDoubleSpace(prefixExpresssion); //remove double space to avid stoi error
//		cout << prefixExpresssion << endl;
//		solvedExression = polishNotationHRS(prefixExpresssion);
//		break;
//	default:
//		break;
//	}
//	
//
//	//checking for post fix
//	//string infixExpression = "24 * (490 + 6 / 12 )";
//	//string infixExpression = "(5*(((9+8)*(4*6))+7))";
//	//string infixExpression = "4*2+3*2+1";
//	// 
//	//infixExpression = removeSpaces(infixExpression); //remove the space from the infix expression.
//	//string postfixExpresssion=makePostFix(infixExpression);
//	//postfixExpresssion=removeDoubleSpace(postfixExpresssion); //remove double space to avid stoi error
//	//string solvedExression = polishNotationHRS(postfixExpresssion);
//
//
//	////checking 
//	//string infixExpression = "( ( 89 * 9 ) + 78 - 87 + ( 6 % 54 ) * 90 )";
//	//infixExpression = removeSpaces(infixExpression); //remove the space from the infix expression.
//	////now reverse
//	//string reverseExpression = reverseInfix(infixExpression);//1s step reverse
//	//string prefixExpresssion = makePostFix(reverseExpression);//2nd solve as postfix
//	////cout << "reverseExpression: through main :" << reverseExpression << endl;
//	////cout << "through main :" << prefixExpresssion << endl;
//	////prefixExpresssion = reverseInfix(prefixExpresssion);// 3rd 
//	//prefixExpresssion = removeDoubleSpace(prefixExpresssion); //remove double space to avid stoi error
//	//cout << prefixExpresssion << endl;
//	//string solvedExression = polishNotationHRS(prefixExpresssion);
//	return 0;
//}