#include <string>

class NotifierBase {
public:
    virtual void Notify(const std::string& message) const {}
};

class SmsNotifier: public NotifierBase {
private:
    std::string phone;
public:
    SmsNotifier(const std::string& s): phone(s) {}
    void Notify(const std::string& message) const override {
        SendSms(phone, message);
    }
};

class EmailNotifier: public NotifierBase {
private:
    std::string email;
public:
    EmailNotifier(const std::string& s): email(s) {}
    void Notify(const std::string& message) const override {
        SendEmail(email, message);
    }
};

