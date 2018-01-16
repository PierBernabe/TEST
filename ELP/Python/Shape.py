class Shape:
    def __init__(self, x = 0, y = 0):
        self.x = x
        self.y = y
    def __repr__(self):
        return "({0},{1})".format(self.x, self.y)
    def translate(self, dx, dy):
        self.x += dx
        self.y += dy
    def area(self):
        pass
    def perimeter(self):
        pass

class Cirle(Shape):
    def __init__(self,x = 0, y = 0, r = 0):
        super().__init__(x, y)
        self.r = r
    def __repr__(self):
        return "({0},{1}:{2})".format(self.x, self.y, self.r)
    def area(self):
        return 3.14 * self.r ** 2
    def perimeter(self):
        return 2 * 3.14 * self.r

class Rectangle(Shape):
    def __init__(self,x = 0, y = 0, largeur = 1 , longueur = 1):
        super().__init__(x, y)
        self.largeur = largeur
        self.longueur = longueur
    def __repr__(self):
        return "({0},{1}:{2},{3})".format(self.x, self.y, self.largeur, self.longueur)
    def area(self):
        return self.largeur * self.longueur
    def perimeter(self):
        return 2 * self.largeur + 2 * self.longueur

class Square(Rectangle,Shape):
    def __init__(self,x = 0, y = 0, longueur = 1 ):
        super().__init__(x, y, longueur, longueur)
