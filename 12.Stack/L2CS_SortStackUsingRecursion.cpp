#include <bits/stdc++.h> 

void sortedInsert( stack<int> &stack , int x ){
	if( ( stack.empty() ) || ( !stack.empty() && stack.top() < x ) ){
		stack.push( x ) ;
		return ;
	}

	int num = stack.top() ;
	stack.pop() ;

	sortedInsert( stack , x ) ;

	stack.push( num ) ;
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if( stack.empty() ){
		return ;
	}

	int temp = stack.top() ;
	stack.pop() ;

	// recursive call
	sortStack( stack ) ;

	sortedInsert( stack , temp ) ;
}