/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daalmeid <daalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:09:52 by daalmeid          #+#    #+#             */
/*   Updated: 2022/09/20 16:37:45 by daalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers.hpp"
#include <deque>
#include <vector>

void	stack_tests(void) {

	ft::stack<std::string>	stk;

	stk.push("24");
	std::cout << stk.top() << std::endl;
	stk.push("42");
	std::cout << stk.top() << std::endl;
	stk.push("424");
	std::cout << stk.top() << std::endl;
	stk.push("222");
	std::cout << stk.top() << std::endl;
	stk.push("123");
	std::cout << stk.top() << std::endl;
	stk.push("1");
	std::cout << stk.top() << std::endl;

	std::cout << "Size: " << stk.size() << std::endl;
	std::cout << "Is this stack empty? " << (stk.empty()? "true" : "false") << std::endl;
	ft::stack<std::string>	newStk(stk);


	stk.pop();
	std::cout << stk.top() << std::endl;
	stk.pop();
	std::cout << stk.top() << std::endl;
	stk.pop();
	std::cout << stk.top() << std::endl;
	stk.pop();
	std::cout << stk.top() << std::endl;
	stk.pop();
	std::cout << stk.top() << std::endl;
	stk.pop();
	
	std::cout << "Size: " << stk.size() << std::endl;
	std::cout << "Is this stack empty? " << (stk.empty()? "true" : "false") << std::endl;
	
	newStk = stk;

	std::cout << "Size of copy: " << newStk.size() << std::endl;
	std::cout << "Is this copy stack empty? " << (newStk.empty()? "true" : "false") << std::endl;

	newStk.push("42");

	if (newStk == stk)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (newStk != stk)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (newStk > stk)
        std::cout << "> operator is correct." << std::endl;
    else
        std::cout << "> operator is not working properly." << std::endl;
    if (newStk < stk)
        std::cout << "< operator is not working properly." << std::endl;
    else
        std::cout << "< operator is correct." << std::endl;
    if (newStk >= stk)
        std::cout << ">= operator is correct." << std::endl;
    else
        std::cout << ">= operator is not working properly." << std::endl;
    if (newStk <= stk)
        std::cout << "<= operator is not working properly." << std::endl << std::endl;
    else
	{
        std::cout << "<= operator is correct." << std::endl << std::endl;
	}

	std::cout << ".**********************************." << std::endl;
	std::cout << "|       OG Containers Tests        |" << std::endl;
	std::cout << " ********************************** " << std::endl;

	
	ft::stack<std::string, std::deque<std::string> >	OGstk;

	OGstk.push("24");
	std::cout << OGstk.top() << std::endl;
	OGstk.push("42");
	std::cout << OGstk.top() << std::endl;
	OGstk.push("424");
	std::cout << OGstk.top() << std::endl;
	OGstk.push("222");
	std::cout << OGstk.top() << std::endl;
	OGstk.push("123");
	std::cout << OGstk.top() << std::endl;
	OGstk.push("1");
	std::cout << OGstk.top() << std::endl;

	std::cout << "Size: " << OGstk.size() << std::endl;
	std::cout << "Is this stack empty? " << (OGstk.empty()? "true" : "false") << std::endl;
	
	ft::stack< std::string, std::deque<std::string> >	newOGStk(OGstk);


	OGstk.pop();
	std::cout << OGstk.top() << std::endl;
	OGstk.pop();
	std::cout << OGstk.top() << std::endl;
	OGstk.pop();
	std::cout << OGstk.top() << std::endl;
	OGstk.pop();
	std::cout << OGstk.top() << std::endl;
	OGstk.pop();
	std::cout << OGstk.top() << std::endl;
	OGstk.pop();
	
	std::cout << "Size: " << OGstk.size() << std::endl;
	std::cout << "Is this stack empty? " << (OGstk.empty()? "true" : "false") << std::endl;
	
	newOGStk = OGstk;

	std::cout << "Size of copy: " << newOGStk.size() << std::endl;
	std::cout << "Is this copy stack empty? " << (newOGStk.empty()? "true" : "false") << std::endl;

	newOGStk.push("42");

	if (newOGStk == OGstk)
        std::cout << "== operator is not working properly." << std::endl;
    else
        std::cout << "== operator is correct." << std::endl;
    if (newOGStk != OGstk)
        std::cout << "!= operator is correct." << std::endl;
    else
        std::cout << "!= operator is not working properly." << std::endl;
    if (newOGStk > OGstk)
        std::cout << "> operator is correct." << std::endl;
    else
        std::cout << "> operator is not working properly." << std::endl;
    if (newOGStk < OGstk)
        std::cout << "< operator is not working properly." << std::endl;
    else
        std::cout << "< operator is correct." << std::endl;
    if (newOGStk >= OGstk)
        std::cout << ">= operator is correct." << std::endl;
    else
        std::cout << ">= operator is not working properly." << std::endl;
    if (newOGStk <= OGstk)
        std::cout << "<= operator is not working properly." << std::endl << std::endl;
    else
	{
        std::cout << "<= operator is correct." << std::endl << std::endl;
	}

	// std::vector<int>	vec(100000000, 42);
	// ft::stack<int, std::vector<int> > vecStack(vec);

	// for (size_t i = 1; i < 100000000; i++)
	// 	vecStack.pop();
	// for (size_t i = 1; i < 100000000; i++)
	// 	vecStack.push(42);
}