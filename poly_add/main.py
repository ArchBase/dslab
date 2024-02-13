class polynomial:
    def __init__(self, no_of_terms) -> None:
        self.coefficients = []
        self.exponents = []
        for i in range(no_of_terms):
            self.coefficients.append(0)