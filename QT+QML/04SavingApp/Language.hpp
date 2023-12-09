#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP

#include <QString>
#include <map>

enum Languages
{
    Spanish,
    English
};

enum Vocabulary
{
    FundWord,
    ExpenseWord,
    SavingsWord,
    HousingWord,
    FoodWord,
    TransportationWord,
    EntertainmentWord,
    TravelWord,
    ClothingWord,
    DebtsWord,
    CarWord,
    AcceptWord,
    ResetWord
};

class WordBook
{
    public:
        WordBook();
        std::map<Vocabulary, QString> getLanguage(Languages language);
    private:
        std::map<Vocabulary, QString> m_spanish;
        std::map<Vocabulary, QString> m_english;
        void setSpanish();
        void setEnglish();
};

#endif // LANGUAGE_HPP
