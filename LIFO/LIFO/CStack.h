#ifndef CSTACK_H
#define CSTACK_H
#include <memory>
#include "CNode.h"
	template<typename T>
	class CStack 
	{
		private :
			int m_Capacity;
			std::shared_ptr<CNode<T>> m_Bottom;
			std::shared_ptr<CNode<T>> m_Up; // top of the stack

		public :
			CStack(const int & capacity = 0);
			CStack(const CStack & stack);
			bool empty() const;
			bool full();
			std::shared_ptr<CNode<T>> top() const;
			void push(const T & Val);
			void pop();
			void show();
	};

	template<typename T>
	CStack<T>::CStack(const int & capacity) : m_Bottom (new CNode<T> ()), m_Up(new CNode<T>()), m_Capacity(capacity)
																																
	{
	}
	template <typename T>
	CStack<T>::CStack(const CStack & stack) : m_Bottom(stack.m_Bottom), m_Up(stack.m_Up), m_Capacity(stack.m_Capacity)
	{

	}

	template <typename T>
	bool CStack<T>::empty() const
	{
		return (m_Bottom->GetNextNode() == nullptr) ? true : false;
	}

	template <typename T>
	bool CStack<T>::full()
	{
		std::shared_ptr<CNode<T>> temp(m_Bottom->GetNextNode());
		unsigned i = 1;
		while (temp != m_Up->GetPrevNode())
		{
			++i;
			temp = temp->GetNextNode();
		}
		if (i >= m_Capacity)
		{
			return true;
		}
		else return false;
	}

	template <typename T>
	std::shared_ptr<CNode<T>> CStack<T>::top() const
	{
		return m_Up->GetPrevNode();
	}

	template <typename T>
	void CStack<T>::push(const T & Val)
	{
		if (this->empty())
		{
			std::shared_ptr<CNode<T>> temp(new CNode<T>(Val, m_Bottom, m_Bottom->GetNextNode()));

			m_Bottom->SetNextNode(temp);
			m_Up->SetPrevNode(temp);
			std::cout << "Le premier element a bien ete ajoute et est : " << m_Bottom->GetNextNode()->GetData() << std::endl;
		}
		else if (!(this->full()))
		{
			std::shared_ptr<CNode<T>> temp(new CNode<T>(Val,m_Up->GetPrevNode(), m_Up));
			m_Up->GetPrevNode()->SetNextNode(temp);
			m_Up->SetPrevNode(temp);
			std::cout << "L'element " << this->top()->GetData() << " a bien ete ajoute" << std::endl;
			
		}
		else
		{
			std::cout << "insertion de la valeur " << Val << " car la pile est pleine" << std::endl;
			std::cout << "le dernier element inserer est" << m_Up->GetPrevNode()->GetData() << std::endl;
			return;
		}


	}
	template <typename T> 
	void CStack<T>::pop()
	{
		
		std::shared_ptr<CNode<T>> temp = this->top();
		
		m_Up->SetPrevNode(temp->GetPrevNode());
		temp->GetPrevNode()->SetNextNode(m_Up);
		std::cout << temp->GetData() << " a bien ete supprimer de la pile" << std::endl;
		

	}

	template <typename T>
	void CStack<T>::show()
	{
		for (std::shared_ptr<CNode<T>> temp(m_Up->GetPrevNode()); temp != m_Bottom ; temp = temp->GetPrevNode())
		{
			std::cout << "-----" << std::endl;
			std::cout << "| " << temp->GetData() << " |" <<std::endl;

		}
		std::cout << "-----" << std::endl;
	}
	



#endif
