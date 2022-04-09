#include "gmock/gmock.h"
#include <gmock/gmock-function-mocker.h>
#include "Card.h"
#include "CardDefinitions.h"

class CardMock : public Card{

    public:
    CardMock():Card(NONE){}
    MOCK_METHOD(bool, IsVisible, ());
    MOCK_METHOD(void, Draw, ());
    MOCK_METHOD(int, GetCardId, (), ( const, override ));
    MOCK_METHOD(void, Show, ());

};
