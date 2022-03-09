#include <vector>
#include <iostream>

class Var {
    private:
        float coeff_;
        float exp_;

    public:
        Var(float coeff, float exp)
            :coeff_(coeff)
            ,exp_(exp)
        {}

        ~Var() {}

        float get_coeff() const {
            return this->coeff_;
        }

        void set_coeff(float coeff) {
            coeff_ = coeff;
        }

        float get_exp() const {
            return this->exp_;
        }
};

class Polynomial {
    private:
        std::vector<Var> vars_;
        int size_;

    public:
        explicit Polynomial(std::vector<Var> vars, int size)
            :vars_(vars)
            ,size_(size)
        {}

        Polynomial(const Polynomial& p)
            :vars_(p.vars_)
            ,size_(p.size_)
        {}

        ~Polynomial() {}

        std::vector<Var> get_vars() const {
            return this->vars_;
        }

        int get_size() const {
            return this->size_;
        }

        Polynomial& operator=(const Polynomial& p) {
            vars_ = p.vars_;
            size_ = p.size_;
            return *this;
        }

        bool operator==(const Polynomial& p) {
            if (vars_ == p.vars_) {
                return true;
            };
            return false;
        }

        bool operator!=(const Polynomial& p) {
            if (vars_ == p.vars_) {
                return false;
            };
            return true;
        }

        Var operator[](int index) const {
            return this->vars_[index];
        }

        Polynomial& operator+(const Polynomial& p) {
            Polynomial pol = Polynomial(vars_, size_);
            int size = size_;
            if (size_ > p.size_) {
                size = p.get_size();
            };
            for (int i = 0; i < size; i++) {
                pol.vars_[i].set_coeff(vars_[i].get_coeff() + p.get_vars()[i].get_coeff());
            };
        }

        Polynomial& operator-(const Polynomial& p) {
            
        }

        Polynomial& operator+=(const Polynomial& p) {
            
        }

        Polynomial& operator-=(const Polynomial& p) {

        }

        Polynomial& operator*(const Polynomial& p) {

        }

        Polynomial& operator/(const Polynomial& p) {

        }

        Polynomial& operator*=(const Polynomial& p) {

        }

        Polynomial& operator/=(const Polynomial& p) {
            
        }

        friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);

        friend std::istream& operator>>(std::istream& is, const Polynomial& p);
};

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    int size = p.get_size();
    for (int i = 0; i < size; i++) {
        float coeff = p[i].get_coeff();
        float exp = p[i].get_exp();
        os << coeff << "x" << i+1 << "^" << exp;
    };
    return os;
}

int main() {
    return 0;
}