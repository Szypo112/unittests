// FakeIt_UnitTests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "gtest/gtest.h"
#include <fakeit.hpp>

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
}