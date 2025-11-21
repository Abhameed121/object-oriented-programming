
        #include <iostream>
        using namespace std;

        class bankAccount {
        private:
        
            int accountNumber;
            float balance;

        public:
            bankAccount(int accountNum = 0, float initialBalance = 0.0) {
                accountNumber = accountNum;
                balance = initialBalance;
            }

    
            void setAccountNumber(int accountNum) {
                accountNumber = accountNum;
            }
                int getAccountNumber()  {
                return accountNumber;
        }
                 float  getBalance() {
                return balance;
            }

            void deposit(double amount) {
                if (amount > 0)
                    balance = balance +  amount;
                else
                    cout << "Deposit amount must be positive." << endl;
    }
                virtual void withdraw(double amount) {
                if (amount > 0 && amount <= balance)
                    balance = balance -  amount;
                else
                    cout << "Invalid withdrawal amount." << endl;
    }
            void printAccountInfo() {
                cout << "Account Number: " << accountNumber << endl;
                cout << "Balance: " << balance << endl;
    }};

        // Derived class: checkingAccount
       
        class checkingAccount : public bankAccount {
        private:
            float interestRate;
            float minimumBalance;
            float  serviceCharges;

        public:
            // Constructor to initialize checking account with additional fields
    checkingAccount(int aaccountNum =0, float ninitialBalance=0.0, float interest=0.0,
    float minBalance =0.0, float serviceharge =0.0):bankAccount(accountNum, initialBalance), interestRate(interest), minimumBalance(minBalance),
     serviceCharges(serviceCharge) {}

            // Set interest rate
            void setInterestRate(float interest) {
                interestRate = interest;
            }

            // Get interest rate
            float getInterestRate() {
                return interestRate;
            }

            // Set minimum balance
            void setMinimumBalance(float minBalance) {
                minimumBalance = minBalance;
            }

            // Get minimum balance
            float getMinimumBalance(){
                return minimumBalance;
            }

            // Set service charges
            void setServiceCharges(float charges) {
                serviceCharges = charges;
            }

            // Get service charges
            float getServiceCharges(){
                return serviceCharges;
            }

            // Post interest to the account
            void postInterest() {
            float interestAmount = getBalance() * (interestRate / 100);
                deposit(interestAmount);
            }

            // Check if balance is less than minimum balance
            bool isBalanceBelowMinimum()  {
                return getBalance() < minimumBalance;
            }

            // Override withdraw to include service charge if balance is below minimum
            void withdraw(float amount) {
                if (isBalanceBelowMinimum()) {
                    cout << "Balance is below minimum, service charges applied!" << endl;
                    deposit(-serviceCharges); // Apply service charges
                }
                bankAccount::withdraw(amount); // Call base class withdraw
            }

            // Write a check (assumes withdrawal)
            void writeCheck(float amount) {
                withdraw(amount);
            }

            // Print account information (including additional info)
            void printAccountInfo()  {
                bankAccount::printAccountInfo();
                cout << "Interest Rate: " << interestRate << "%" << endl;
                cout << "Minimum Balance: " << minimumBalance << endl;
                cout << "Service Charges: " << serviceCharges << endl;
            }
        };

        // Derived class: savingsAccount
        class savingsAccount : public bankAccount {
        private:
            float interestRate;

        public:
            // Constructor to initialize savings account with interest rate
            savingsAccount(int accountNum = 0, float initialBalance = 0.0, float  interest = 0.0)
                : bankAccount(accountNum, initialBalance), interestRate(interest) {}

            // Set interest rate
            void setInterestRate(float interest) {
                interestRate = interest;
            }

            // Get interest rate
            float getInterestRate()  {
                return interestRate;
            }

            // Post interest to the account
            void postInterest() {
                float interestAmount = getBalance() * (interestRate / 100);
                deposit(interestAmount);
            }

            // Override withdraw method to add custom logic
            void withdraw(double amount) override {
                if (amount > getBalance()) {
                    cout << "Insufficient funds to withdraw " << amount << endl;
                } else {
                    bankAccount::withdraw(amount);
                }
            }

            // Print account information (including interest rate)
            void printAccountInfo() const {
                bankAccount::printAccountInfo();
                cout << "Interest Rate: " << interestRate << "%" << endl;
            }
        };

        int main() {
        
            checkingAccount checkAcc(12345, 1000.0, 2.5, 500.0, 10.0);
            checkAcc.printAccountInfo();
            checkAcc.deposit(200);
            checkAcc.withdraw(100);
            checkAcc.writeCheck(300);
            checkAcc.postInterest();
            checkAcc.printAccountInfo();

            cout << endl;

            savingsAccount saveAcc(67890, 2000.0, 1.5);
            saveAcc.printAccountInfo();
            saveAcc.deposit(500);
            saveAcc.withdraw(700);
            saveAcc.postInterest();
            saveAcc.printAccountInfo();

            return 0;
        }
