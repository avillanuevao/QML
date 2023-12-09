#include "Language.hpp"

WordBook::WordBook()
{
    setSpanish();
    setEnglish();
}

void WordBook::setSpanish()
{
    m_spanish[Vocabulary::FundWord] = "Fondo";
    m_spanish[Vocabulary::ExpenseWord] = "Gasto";
    m_spanish[Vocabulary::SavingsWord] = "Ahorro";
    m_spanish[Vocabulary::HousingWord] = "Hogar";
    m_spanish[Vocabulary::FoodWord] = "Comida";
    m_spanish[Vocabulary::TransportationWord] = "Transporte";
    m_spanish[Vocabulary::EntertainmentWord] = "Entretenimiento";
    m_spanish[Vocabulary::TravelWord] = "Viajes";
    m_spanish[Vocabulary::ClothingWord] = "Ropa";
    m_spanish[Vocabulary::DebtsWord] = "Deudas";
    m_spanish[Vocabulary::AcceptWord] = "Aceptar";
    m_spanish[Vocabulary::ResetWord] = "Resetear";
    m_spanish[Vocabulary::EnglishWord] = "Ingles";
    m_spanish[Vocabulary::SpanishWord] = "Español";
}

void WordBook::setEnglish()
{
    m_english[Vocabulary::FundWord] = "Fund";
    m_english[Vocabulary::ExpenseWord] = "Expense";
    m_english[Vocabulary::SavingsWord] = "Savings";
    m_english[Vocabulary::HousingWord] = "Housing";
    m_english[Vocabulary::FoodWord] = "Food";
    m_english[Vocabulary::TransportationWord] = "Transport";
    m_english[Vocabulary::EntertainmentWord] = "Enterteinment";
    m_english[Vocabulary::TravelWord] = "Travel";
    m_english[Vocabulary::ClothingWord] = "Clothing";
    m_english[Vocabulary::DebtsWord] = "Debts";
    m_english[Vocabulary::AcceptWord] = "Accept";
    m_english[Vocabulary::ResetWord] = "Reset";
    m_english[Vocabulary::EnglishWord] = "English";
    m_english[Vocabulary::SpanishWord] = "Spanish";
}

std::map<Vocabulary, QString> WordBook::getLanguage(Languages language)
{
    switch (language) {
        case Languages::Spanish:
        return m_spanish;
        break;
        case Languages::English:
        return m_english;
        break;
    }
}
