# 1. Triangle Checker

print("--- Triangle Checker ---")
# Get side lengths as floats (to allow decimals)
a = float(input("Enter length of side a: "))
b = float(input("Enter length of side b: "))
c = float(input("Enter length of side c: "))

# --- Step 1: Check for Validity ---
# The sum of any two sides must be greater than the third side.
if (a + b > c) and (a + c > b) and (b + c > a):
    print("This is a VALID triangle.")
    
    # --- Step 2: Classify the triangle ---
    
    # Check for Equilateral, Isosceles, or Scalene
    if a == b == c:
        print("It is an Equilateral triangle (all sides are equal).")
    elif a == b or b == c or a == c:
        print("It is an Isosceles triangle (two sides are equal).")
    else:
        print("It is a Scalene triangle (no sides are equal).")

    # --- Step 2b: Check for Right-Angle (independent check) ---
    # Use Pythagorean theorem: a^2 + b^2 = c^2
    # We must sort the sides to find the longest side (hypotenuse)
    sides = sorted([a, b, c])
    
    # Check if (side1^2 + side2^2) is equal to (hypotenuse^2)
    # We use abs() and a small tolerance (0.00001) for float precision
    if abs((sides[0]**2 + sides[1]**2) - sides[2]**2) < 0.00001:
        print("It is also a Right-Angled triangle.")

else:
    print("This is an INVALID triangle (the side lengths do not form a triangle).")