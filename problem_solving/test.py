class Fraction:
    
    def __init__(self, top, bottom):
        self.num = top
        self.den = bottom

    def __str__(self):
        return str(self.num) + "/" + str(self.den)
    
    def __add__(self, other):
        new_num = self.num * other.den + self.den * other.num
        new_den = self.den * other.den
        common = gcd(new_num, new_den)
        return Fraction(new_num // common, new_den // common)
    
    def __eq__(self, other):
        first_num = self.num * other.den
        second_num = self.den * other.num
        return first_num == second_num
    
    def __mul__(self, other):
        new_num = self.num * other.num
        new_den = self.den * other.den
        common = gcd(new_num, new_den)
        return Fraction(new_num // common, new_den // common)
    
    def __sub__(self, other):
        new_num = self.num * other.den - self.den * other.num
        new_den = self.den * other.den
        common = gcd(new_num, new_den)
        return Fraction(new_num // common , new_den // common)
    
    def __truediv__(self, other):
        new_num = self.num * other.den
        new_den = self.den * other.num
        common = gcd(new_num, new_den)
        return Fraction(new_num // common, new_den // common)
    
    def __gt__(self, other):
        first = other.den * (self.num / self.den)
        second = self.den * (other.num / other.den)
        return first > second
    
    def __ge__(self, other):
        first = other.den * (self.num / self.den)
        second = self.den * (other.num / other.den)
        return first >= second
    
    def get_num(self):
        return self.num

    def get_den(self):
        return self.den


def gcd(a, b):
    while (a % b != 0):
        old_a = a
        old_b = b

        a = old_b
        b = old_a % old_b
    return b

if __name__ == "__main__":
    f1 = Fraction(1, 4)
    f2 = Fraction(1, 4)
    print(f1+f2)
    print(f1 == f2)
    print(f1 * f2)
    print(f1 - f2)
    print(f1 / f2)
    print(f1.get_den())
    print(f1.get_num())
    print(f1 >= f2)