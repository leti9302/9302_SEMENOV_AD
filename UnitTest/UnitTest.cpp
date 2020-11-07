#include "CppUnitTest.h"
#include "../Lab_1/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(ListTesting)
	{
	public:
		List* lst;
		// before each test
		TEST_METHOD_INITIALIZE(setUp)
		{
			lst = new List();
		}
		// after each test
		TEST_METHOD_CLEANUP(cleanUp)
		{
			delete lst;
		}

		TEST_METHOD(is_the_list_empty) {
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(is_the_list_not_empty) {
			lst->push_back(0);
			Assert::IsFalse(lst->isEmpty());
		}

		TEST_METHOD(is_the_size_correct) {
			Assert::AreEqual(int(lst->get_size()), 0);
		}

		TEST_METHOD(incorrect_size) {
			lst->push_back(0);
			Assert::AreNotEqual(int(lst->get_size()), 0);
		}

		TEST_METHOD(at_correct_index)
		{
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			Assert::AreEqual(lst->at(1), 2);
		}

		TEST_METHOD(at_incorrect_index)
		{
			try {
				lst->at(-1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}

		}

		TEST_METHOD(does_push_back_work) {
			lst->push_back(1);
			Assert::AreEqual(lst->at(0), 1);
		}

		TEST_METHOD(push_back_size_test) {
			lst->push_back(2);
			Assert::AreEqual(int(lst->get_size()), 1);
		}

		TEST_METHOD(does_push_front_work) {
			lst->push_front(6);
			Assert::AreEqual(lst->at(0), 6);
		}

		TEST_METHOD(push_front_size_test) {
			lst->push_front(3);
			Assert::AreEqual(int(lst->get_size()), 1);
		}

		TEST_METHOD(pop_back_test) {
			lst->push_back(3);
			lst->push_back(2);
			lst->push_back(1);
			lst->pop_back();
			Assert::AreEqual(lst->at(1), 2);
		}

		TEST_METHOD(pop_back_size_test) {
			lst->push_back(4);
			lst->push_back(5);
			lst->pop_back();
			Assert::AreEqual(int(lst->get_size()), 1);
		}

		TEST_METHOD(pop_back_1_elem_test) {
			lst->push_back(1);
			lst->pop_back();
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(pop_back_empty_test) {
			lst->pop_back();
			Assert::AreEqual(int(lst->get_size()), 0);
		}

		TEST_METHOD(pop_front_test) {
			lst->push_front(1);
			lst->push_front(2);
			lst->push_front(3);
			lst->pop_front();
			Assert::AreEqual(lst->at(0), 2);
		}

		TEST_METHOD(pop_front_size_test) {
			lst->push_front(4);
			lst->push_front(5);
			lst->pop_front();
			Assert::AreEqual(int(lst->get_size()), 1);
		}

		TEST_METHOD(pop_front_1_elem_test) {
			lst->push_front(1);
			lst->pop_front();
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(pop_front_empty_test) {
			lst->pop_front();
			Assert::AreEqual(int(lst->get_size()), 0);
		}

		TEST_METHOD(insert_test) {
			lst->push_front(1);
			lst->push_front(1);
			lst->push_front(1);
			lst->insert(2, 1);
			Assert::AreEqual(lst->at(1), 2);
		}

		TEST_METHOD(insert_size_test) {
			lst->push_front(1);
			lst->push_front(1);
			lst->push_front(1);
			lst->insert(2, 1);
			Assert::AreEqual(int(lst->get_size()), 4);
		}

		TEST_METHOD(insert_to_empty_list)
		{
			lst->insert(1, 0);
			Assert::AreEqual(lst->at(0), 1);
		}

		TEST_METHOD(insert_to_empty_list_incorrect)
		{
			try {
				lst->insert(1, 4);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(remove_test) {
			lst->push_back(5);
			lst->push_back(6);
			lst->push_back(7);
			lst->remove(1);
			Assert::AreEqual(lst->at(1), 7);
		}

		TEST_METHOD(remove_incorrect_test) {
			try {
				lst->remove(1);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Index is greater than list size", e.what());
			}
		}

		TEST_METHOD(remove_size_test) {
			lst->push_back(5);
			lst->push_back(6);
			lst->push_back(7);
			lst->remove(1);
			Assert::AreEqual(int(lst->get_size()), 2);
		}

		TEST_METHOD(remove_test_empty) {
			lst->push_back(5);
			lst->remove(0);
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(clear_test) {
			lst->push_back(1);
			lst->push_back(6);
			lst->push_back(9);
			lst->clear();
			Assert::IsTrue(lst->isEmpty());
		}

		TEST_METHOD(set_test)
		{
			lst->push_back(0);
			lst->push_back(0);
			lst->push_back(0);
			lst->set(2, 1);
			Assert::AreEqual(lst->at(2), 1);
		}

		TEST_METHOD(set_size_test)
		{
			lst->push_back(0);
			lst->push_back(0);
			lst->push_back(0);
			lst->set(2, 1);
			Assert::AreEqual(int(lst->get_size()), 3);
		}

		TEST_METHOD(is_new_list_added) {
			List* lst2;
			lst2 = new List();
			lst->push_back(4);
			lst2->push_back(23);
			lst2->push_back(9);
			lst->push_back(*lst2);
			Assert::AreEqual(lst->at(2), 9);
			lst2->clear();
			delete lst2;
		}

		TEST_METHOD(empty_list_added) {
			List* lst2;
			lst2 = new List();
			lst->push_back(*lst2);
			Assert::IsTrue(lst->isEmpty());
			delete lst2;
		}
	};
}
