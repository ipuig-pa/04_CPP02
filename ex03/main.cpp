/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipuig-pa <ipuig-pa@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:37:52 by ipuig-pa          #+#    #+#             */
/*   Updated: 2025/02/11 11:52:46 by ipuig-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

void runTest(int testNumber, Point const& a, Point const& b, Point const& c, Point const& point, bool expectedInside) 
{
	bool result = bsp(a, b, c, point);
	std::cout << "Test " << testNumber << ": Point is ";
	if (!result)
		std::cout << "not ";
	std::cout << "inside the triangle";
	if (result != expectedInside)
		std::cout << " (FAILED: expected " << (expectedInside ? "inside" : "outside") << ")";
	std::cout << std::endl;
}

int main(void) 
{
	// Test 0: Basic triangle with point inside
	runTest(0, 
		Point(0.0f, 0.0f),    // a: Origin
		Point(4.0f, 0.0f),    // b: Right on x-axis
		Point(2.0f, 4.0f),    // c: Above
		Point(2.0f, 2.0f),    // point: Should be inside
		true
	);

	// Test 1: Point on edge (should be outside)
	runTest(1,
		Point(0.0f, 0.0f),
		Point(4.0f, 0.0f),
		Point(2.0f, 4.0f),
		Point(2.0f, 0.0f),    // On bottom edge
		false
	);

	// Test 2: Point on vertex (should be outside)
	runTest(2,
		Point(0.0f, 0.0f),
		Point(4.0f, 0.0f),
		Point(2.0f, 4.0f),
		Point(0.0f, 0.0f),    // On vertex a
		false
	);

	// Test 3: Point clearly outside
	runTest(3,
		Point(0.0f, 0.0f),
		Point(4.0f, 0.0f),
		Point(2.0f, 4.0f),
		Point(5.0f, 5.0f),    // Outside
		false
	);

	// Test 4: Complex triangle with point inside
	runTest(4,
		Point(1.5f, 1.5f),
		Point(6.2f, 3.3f),
		Point(3.8f, 7.5f),
		Point(3.5f, 4.0f),    // Should be inside
		true
	);

	// Test 5: Point very close to edge (inside)
	runTest(5,
		Point(0.0f, 0.0f),
		Point(4.0f, 0.0f),
		Point(2.0f, 4.0f),
		Point(2.0f, 0.1f),    // Just above edge
		true
	);

	// Test 6: Point very close to edge (outside)
	runTest(6,
		Point(0.0f, 0.0f),
		Point(4.0f, 0.0f),
		Point(2.0f, 4.0f),
		Point(2.0f, -0.1f),   // Just below edge
		false
	);

	// Test 7: Triangle in negative quadrant
	runTest(7,
		Point(-4.0f, -2.0f),
		Point(-1.0f, -2.0f),
		Point(-2.5f, -5.0f),
		Point(-2.5f, -3.0f),  // Should be inside
		true
	);

	// Test 8: Triangle crossing quadrants (inside)
	runTest(8,
		Point(-2.0f, 2.0f),
		Point(2.0f, -2.0f),
		Point(-3.0f, -3.0f),
		Point(-1.0f, -1.0f),  // Should be inside
		true
	);

	// Test 9: Edge case near negative coordinates
	runTest(9,
		Point(-1.0f, -1.0f),
		Point(2.0f, -1.0f),
		Point(0.5f, 2.0f),
		Point(0.0f, -0.99f),  // Very close to edge, inside
		true
	);

	// Test 10: Triangle crossing quadrants (outside)
	runTest(10,
		Point(-2.0f, 2.0f),    // Upper left quadrant
		Point(3.0f, -1.0f),    // Lower right quadrant
		Point(-1.0f, -3.0f),   // Lower left quadrant
		Point(2.0f, 2.0f),     // Outside in upper right quadrant
		false
	);

	return 0;
}
