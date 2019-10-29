#include "stack.h"

int main()
{
	Stack st;

	Book * b = new Book(123);
	st.push(b);

	b = new Book(456);
	st.push(b);

	b = new Book(789);
	st.push(b);
	st.print();


	st.pop();

	st.print();

	return 0;
}