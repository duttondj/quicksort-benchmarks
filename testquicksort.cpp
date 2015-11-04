////////////////////////////////////////////////////////////////////////////////
//
//  Title:  testquicksort.cpp
//  Author: Danny Dutton
//  Date:   11/03/15
//  Desc:   Functions to manage testing the fill_normal and myqsort modules
//
////////////////////////////////////////////////////////////////////////////////

#include <QtTest>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include "myqsort.h"
#include "fill_normal.h"

#ifndef _ARRAYTYPE
#define _ARRAYTYPE
typedef std::vector<double> ArrayType;
#endif


class TestQuickSort : public QObject
{
    Q_OBJECT
public:

private Q_SLOTS:
    void test_fill_normal();
    void test_myqsort();
};

// Test fill_normal
void TestQuickSort::test_fill_normal()
{
    ArrayType data(100);
    fill_normal d;

    // Fill every element of vector with random numbers
    for_each(data.begin(), data.end(), d);

    // Check if data is at the right size
    QVERIFY(data.size() == 100);
}

// Test myqsort
void TestQuickSort::test_myqsort()
{
    ArrayType data1(100);
    ArrayType data2(100);
    fill_normal d1;
    fill_normal d2;

    // Fill every element of vector with random numbers
    for_each(data1.begin(), data1.end(), d1);
    for_each(data2.begin(), data2.end(), d2);

    // Do two quick sorts, sequential and concurrent
    myqsort(data1, 0, data1.size()-1, false);
    myqsort(data2, 0, data2.size()-1, true);

    // Check if data has been sorted
    for (int i = 1; i < data1.size(); i++)
    {
        QVERIFY(data1[i-1] <= data1[i]);
    }

    // Check if data has been sorted
    for (int i = 1; i < data2.size(); i++)
    {
        QVERIFY(data2[i-1] <= data2[i]);
    }
}

QTEST_MAIN(TestQuickSort)
#include "testquicksort.moc"