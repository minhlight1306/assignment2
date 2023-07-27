#include "knight2.h"
//check snt
bool checksnt(int a) {  
    if (a<2) return false;  
    for (int i = 2; i < a ;i++) { 
        if (a%i == 0) return false; 
    }
    return true;
}
bool checkpitago(int so) {
    int a = so / 100;
    int b = (so /10) %10;
    int c = so %10;
    if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a){
        return true;
    }
    else return false;
}
bool BaseOpponent::toHades = false;
bool BaseOpponent::toOmegaWeapon = false;
BaseOpponent *BaseOpponent::create(int a, OpponentType opponentType){
    BaseOpponent* opponent = nullptr;

    switch (opponentType) {
        case OpponentType::MadBear:
            opponent = new MadBearOpponent();
            break;
        case OpponentType::Bandit:
            opponent = new BanditOpponent();
            break;
        case OpponentType::LordLupin:
            opponent = new LordLupinOpponent();
            break;
        case OpponentType::Elf:
            opponent = new ElfOpponent();
            break;
        case OpponentType::Troll:
            opponent = new TrollOpponent();
            break;
        case OpponentType::Tornbery:
            opponent = new TornberyOpponent();
            break;
        case OpponentType::QueenOfCards:
            opponent = new QueenOfCardsOpponent();
            break;
        case OpponentType::NinaDeRings:
            opponent = new NinaDeRingsOpponent();
            break;
        case OpponentType::DurianGarden:
            opponent = new DurianGardenOpponent();
            break;
        case OpponentType::OmegaWeapon:
            opponent = new OmegaWeaponOpponent();
            break;
        case OpponentType::Hades:
            opponent = new HadesOpponent();
            break;
        default:
            return nullptr;
    }
 opponent->a = a;
 return opponent;
}
OpponentType MadBearOpponent::Type(){
    return MadBear;
}
OpponentType BanditOpponent::Type(){
    return Bandit;
}
OpponentType LordLupinOpponent::Type(){
    return LordLupin;
}
OpponentType ElfOpponent::Type(){
    return Elf;
}
OpponentType TrollOpponent::Type(){
    return Troll;
}
OpponentType TornberyOpponent::Type(){
    return Tornbery;
}
OpponentType QueenOfCardsOpponent::Type(){
    return QueenOfCards;
}
OpponentType NinaDeRingsOpponent::Type(){
    return NinaDeRings;
}
OpponentType DurianGardenOpponent::Type(){
    return DurianGarden;
}
OpponentType OmegaWeaponOpponent::Type(){
    return OmegaWeapon;
}
OpponentType HadesOpponent::Type(){
    return Hades;
}
//sk1
void MadBearOpponent::updateKnight(BaseKnight* knight){
    int baseDamage=10, bonusgil=100;
    int level0;
    int level = knight->getlevel();
	int HP = knight->gethp();  
    int gil = knight->getgil();

    level0 = (this->a + 1)%10 + 1;
    
    if (level < level0) {
        HP = HP - baseDamage*(level0 - level);
        knight->sethp(HP);
        knight->getBag()->checkHp();
    }
    else {
        gil+=bonusgil;
        knight->setgil(gil);
    }
}
//sk2
void BanditOpponent::updateKnight(BaseKnight *knight){
    int baseDamage=15, bonusgil=150;
    int level0;
    int level = knight->getlevel();
	int HP = knight->gethp();  
    int gil = knight->getgil();

    level0 = (this->a + 2)%10 + 1;
    
    if (level < level0) {
        HP = HP - baseDamage*(level0 - level);
        knight->sethp(HP);
        knight->getBag()->checkHp();
    }
    else {
        gil+=bonusgil;
        knight->setgil(gil);
    }
}
//sk3
void LordLupinOpponent::updateKnight(BaseKnight *knight){
    int baseDamage=45, bonusgil=450;
    int level0;
    int level = knight->getlevel();
	int HP = knight->gethp();  
    int gil = knight->getgil();

    level0 = (this->a + 3)%10 + 1;
    
    if (level < level0) {
        HP = HP - baseDamage*(level0 - level);
        knight->sethp(HP);
        knight->getBag()->checkHp();
    }
    else {
        gil+=bonusgil;
        knight->setgil(gil);
    }
}
//sk4
void ElfOpponent::updateKnight(BaseKnight *knight){
    int baseDamage=75, bonusgil=750;
    int level0;
    int level = knight->getlevel();
	int HP = knight->gethp();  
    int gil = knight->getgil();

    level0 = (this->a + 4)%10 + 1;
    
    if (level < level0) {
        HP = HP - baseDamage*(level0 - level);
        knight->sethp(HP);
        knight->getBag()->checkHp();
    }
    else {
        gil+=bonusgil;
        knight->setgil(gil);
    }
}
//sk5
void TrollOpponent::updateKnight(BaseKnight *knight){
    int baseDamage=95, bonusgil=800;
    int level0;
    int level = knight->getlevel();
	int HP = knight->gethp();  
    int gil = knight->getgil();

    level0 = (this->a + 5)%10 + 1;
    
    if (level < level0) {
        HP = HP - baseDamage*(level0 - level);
        knight->sethp(HP);
        knight->getBag()->checkHp();
    }
    else {
        gil+=bonusgil;
        knight->setgil(gil);
    }
}
//sk6
void TornberyOpponent::updateKnight(BaseKnight *knight){
    int level0;
    int level = knight->getlevel();
	int HP = knight->gethp();  

    level0 = (this->a + 6)%10 + 1;
    
    if (level < level0) {
    if(knight->getType() != DRAGON){
            knight->setantidote(true);

            if(knight->getantidote() == true){
                knight->getBag()->get(antidote);

                if(knight->getantidote() == true){
                    knight->setantidote(false);
                    knight->getBag()->remove();
                    knight->sethp(knight->gethp()-10);
                    knight->getBag()->checkHp();
                }
            }
        }
    }
    else {
        level+=1;
        knight->setlevel(level);
    }
}
//sk7
void QueenOfCardsOpponent::updateKnight(BaseKnight *knight){
    int level0;
    int level = knight->getlevel();
	int HP = knight->gethp();  
    int gil = knight->getgil();

    level0 = (this->a + 7)%10 + 1;
    if(level<level0 && knight->getType() != PALADIN){
        knight->setgil(gil/2);
    }
    else if(level>level0) knight->setgil(gil*2);
}
//sk8
void NinaDeRingsOpponent::updateKnight(BaseKnight *knight){
    int HP = knight->gethp(); 
    int maxhp = knight->getmaxhp(); 
    int gil = knight->getgil();

    if(gil>=50 && HP<(maxhp/3)) {
        knight->setgil(gil-50);
        HP = HP + (maxhp/5);
        knight->sethp(HP);
    }
}
//sk9
void DurianGardenOpponent::updateKnight(BaseKnight *knight){
    knight->sethp(knight->getmaxhp());
}
//sk10
void OmegaWeaponOpponent::updateKnight(BaseKnight *knight){
    int level = knight->getlevel();
	int HP = knight->gethp();
    int maxhp = knight->getmaxhp();

if(BaseOpponent::toOmegaWeapon == true) return;
    else if(knight->getType() == DRAGON || (HP == maxhp && level == 10)){
        knight->setgil(999);
        knight->setlevel(10);
        BaseOpponent::toOmegaWeapon = true;
    }
    else {
        knight->sethp(0);
        knight->getBag()->checkHp();
    }
}
//sk11
void HadesOpponent::updateKnight(BaseKnight *knight){
    int level = knight->getlevel();
	int HP = knight->gethp();

    if(BaseOpponent::toHades == true) return;

    else if(level == 10 || (knight->getType() == PALADIN && level >= 8)){
        BaseOpponent::toHades = true;
    }
    else {
        knight->sethp(0);
        knight->getBag()->checkHp();
    }
}
/* * * BEGIN implementation of class BaseBag * * */
BaseBag::~BaseBag()
{
    while (size--)
    {
        BaseItem *temp = head;
        head = head->next;
        delete temp;
    }
}
void BaseBag::checkHp(){
    if(size == 0) return;
    BaseItem *curr = head;
    BaseItem *prev = curr->next;
    if(head->canUse(knight)==true){
        size--;
        BaseItem *curr2 = head;
        head = head->next;
        curr2->use(knight);
        delete curr2;
        return;
    }
    if(size >=2 && head->next->canUse(knight)){
        BaseItem *curr2 = head->next;
        head->next = head->next->next;
        curr2->use(knight);
        delete curr2;
        size--;
        return;
    }
    while (prev != NULL){
        if (prev->canUse(knight) == true)
        {
            BaseItem *curr2 = head->next;
            curr->next = head;
            head->next = prev->next;
            head = curr2;
            prev->use(knight);
            size--;
            delete prev;
            break;
        }
        curr = prev;
        prev = prev->next;
    }
}
bool BaseBag::insertFirst(BaseItem *item){
    if (size < Limited || Limited == -1)
    {
        item->next = head;
        head = item;
        size++;
        return true;
    }
    return false;
}
ItemType Antidote::Type(){
    return antidote;
}
ItemType PhoenixDownI::Type(){
    return phoenixdownI;
}
ItemType PhoenixDownII::Type(){
    return phoenixdownII;
}
ItemType PhoenixDownIII::Type(){
    return phoenixdownIII;
}
ItemType PhoenixDownIV::Type(){
    return phoenixdownIV;
}
BaseItem *BaseBag::get(ItemType itemType){    
    if (head == NULL)
        return NULL;
    BaseItem *curr = head;
    BaseItem *prev = curr->next;
    if (head->item == itemType)
    {
        head->use(knight);
        size--;
        BaseItem *curr2 = head;
        head = head->next;
        delete curr2;
        return NULL;
    }
    if (head->canUse(knight) == true)
    {
        size--;
        BaseItem *curr2 = head;
        head = head->next;
        curr2->use(knight);
        delete curr2;
        return NULL;
    }
    if (size >= 2 && head->next->canUse(knight))
    {   
        BaseItem *curr2 = head->next;
        head->next = head->next->next;
        curr2->use(knight);
        size--;
        delete curr2;
        return NULL;
    }
    while (prev != NULL)
    {
        if (prev->item == itemType)
        {
            BaseItem *curr2 = head->next;
            curr->next = head;
            head->next = prev->next;
            head = curr2;
            size--;
            prev->use(knight);
            delete prev;
            return NULL;
        }
        curr = prev;
        prev = prev->next;
    }
    return NULL;
}
string BaseBag::toString() const {
    string list_items;
    BaseItem* current = head;
    while (current != nullptr) {
            if (current->item == antidote) {
                list_items += "Antidote,";
            }
            else if (current->item == phoenixdownI) {
                list_items += "PhoenixI,";
            }
            else if (current->item == phoenixdownII) {
                list_items += "PhoenixII,";
            }
            else if (current->item == phoenixdownIII) {
                list_items += "PhoenixIII,";
            }
            else if (current->item == phoenixdownIV) {
                list_items += "PhoenixIV,";
            }
            current = current->next;
        }
        if (list_items.length() > 0) {
            list_items.erase(list_items.length()-1);
        }
        return "Bag[count=" + to_string(this->size) + ";" + list_items + "]";
}
void BaseBag::remove(){
    for (int i = 0; i < 3 && size != 0; i++)
    {
        BaseItem *temp = head;
        head = head->next;
        size--;
        delete temp;
    }
}
PaladinBag::PaladinBag(BaseKnight *knight, int a, int b){
    this->knight = knight;
    this->Limited=-1;
    this->fail = 0;
    if(a>0){
        for (int i = 0; i < a; i++) {
            insertFirst(new PhoenixDownI());
            if(fail ==4) break;
            fail++;
        }
    }
    if(b>0){
        for (int i = 0; i < b; i++) {
            insertFirst(new Antidote());
            if(fail ==4) break;
            fail++;
        }
    }
}
LancelotBag::LancelotBag(BaseKnight* knight, int a, int b){
    this->knight = knight;
    this->Limited=16;
    this->fail = 0;
    if(a>0){
        for (int i = 0; i < a && size < this->Limited; i++) {
            insertFirst(new PhoenixDownI());
            if(fail ==4) break;
            fail++;
        }
    }
    this->fail=0;
    if(b>0){
        for (int i = 0; i < b && size < this->Limited; i++) {
            insertFirst(new Antidote());
            if(fail ==4) break;
            fail++;
        }
    }
}
DragonBag::DragonBag(BaseKnight* knight, int a, int b){
    this->knight = knight;
    this->Limited=14;
    this->fail = 0;
    if(a>0){
        for (int i = 0; i < a && size < this->Limited; i++) {
            insertFirst(new PhoenixDownI());
            if(fail ==4) break;
            fail++;
        }
    }
}
NormalBag::NormalBag(BaseKnight* knight, int a, int b){
    this->knight = knight;
    this->Limited=19;
    this->fail = 0;
    if(a>0){
        for (int i = 0; i < a && size < this->Limited; i++) {
            insertFirst(new PhoenixDownI());
            if(fail ==4) break;
            fail++;
        }
    }
    this->fail=0;
    if(b>0){
        for (int i = 0; i < b && size < this->Limited; i++) {
            insertFirst(new Antidote());
            if(fail ==4) break;
            fail++;
        }
    }
}
bool Antidote::canUse(BaseKnight *knight){
    if(knight->getantidote()==true){
        return true;
    }
    return false;
}
void Antidote::use(BaseKnight *knight){
    knight->setantidote(false);
}
bool PhoenixDownI::canUse(BaseKnight *knight){
    return knight->gethp()<=0;
}
void PhoenixDownI::use(BaseKnight *knight){
    knight->sethp(knight->getmaxhp());
}
bool PhoenixDownII::canUse(BaseKnight *knight){
    if(knight->gethp()<knight->getmaxhp()/4){
        return true;
    }
    return false;
}
void PhoenixDownII::use(BaseKnight *knight){
    knight->sethp(knight->getmaxhp());
}
bool PhoenixDownIII::canUse(BaseKnight *knight){
    if(knight->gethp()<knight->getmaxhp()/3){
        return true;
    }
    return false;
}
void PhoenixDownIII::use(BaseKnight *knight){
    if(knight->gethp()<=0)
        knight->sethp(knight->getmaxhp()/3);
    else {
        knight->sethp(knight->gethp()+knight->getmaxhp()/4);
    }
}
bool PhoenixDownIV::canUse(BaseKnight *knight){
    if(knight->gethp()<knight->getmaxhp()/2){
        return true;
    }
    return false;
}
void PhoenixDownIV::use(BaseKnight *knight){
    if(knight->gethp()<=0)
        knight->sethp(knight->getmaxhp()/2);
    else {
        knight->sethp(knight->gethp()+knight->getmaxhp()/5);
    }
}
/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
bool BaseKnight::setBag(BaseItem *item){
    return bag->insertFirst(item);
}
BaseKnight * BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) {
    BaseKnight *knight;
    if (checksnt(maxhp)) {
        knight = new PaladinKnight();
        knight->knightType = PALADIN;
        knight->bag = new PaladinBag(knight, phoenixdownI, antidote);
    } else if (checkpitago(maxhp)) {
        knight = new DragonKnight();
        knight->knightType = DRAGON;
        knight->bag = new DragonBag(knight, phoenixdownI, 0);
    } else if (maxhp == 888) {
        knight = new LancelotKnight();
        knight->knightType = LANCELOT;
        knight->bag = new LancelotBag(knight, phoenixdownI, antidote);
    } else {
        knight = new NormalKnight();
        knight->knightType = NORMAL;
        knight->bag = new NormalBag(knight, phoenixdownI, antidote);
    }
knight->setgil(gil);
knight->setid(id);
knight->setmaxhp(maxhp);
knight->sethp(maxhp);
knight->setlevel(level);
knight->isPoisoned = 0;
knight->residualGil = 0;
return knight;
}
bool BaseKnight::fight(BaseOpponent *opponent){
    if(this->hp<=0 && this->gil>=100) {
        this->hp = this->maxhp/2;
        this->gil = this->gil - 100;
    }
    if(this->hp >0) return true;
    return false;
}
bool PaladinKnight::fight(BaseOpponent* opponent)
{
    OpponentType opponentType = opponent->Type();
    switch (opponentType) {
        case OpponentType::MadBear:
            this->setgil(this->getgil() + 100);
            break;
        case OpponentType::Bandit:
            this->setgil(this->getgil() + 150);
            break;
        case OpponentType::LordLupin:
            this->setgil(this->getgil() + 450);
            break;
        case OpponentType::Elf:
            this->setgil(this->getgil() + 750);
            break;
        case OpponentType::Troll:
            this->setgil(this->getgil() + 800);
            break;
        case OpponentType::NinaDeRings:
            if (this->hp < this->maxhp / 3)
                this->hp += this->maxhp / 5;
            break;
        case OpponentType::QueenOfCards: {
            int tempt = this->gil;
            opponent->updateKnight(this);
            if (tempt > this->gil)
                this->gil = tempt;
            break;
        }
        default:
            opponent->updateKnight(this);
            break;
    }

    return BaseKnight::fight(opponent);
}
bool LancelotKnight::fight(BaseOpponent* opponent)
{
    OpponentType opponentType = opponent->Type();
    switch (opponentType) {
        case OpponentType::MadBear:
            this->setgil(this->getgil() + 100);
            break;
        case OpponentType::Bandit:
            this->setgil(this->getgil() + 150);
            break;
        case OpponentType::LordLupin:
            this->setgil(this->getgil() + 450);
            break;
        case OpponentType::Elf:
            this->setgil(this->getgil() + 750);
            break;
        case OpponentType::Troll:
            this->setgil(this->getgil() + 800);
            break;
        default:
            opponent->updateKnight(this);
            break;
    }

    return BaseKnight::fight(opponent);
}
bool DragonKnight::fight(BaseOpponent *opponent){
    OpponentType opponentType = opponent->Type();
    if(opponentType == OmegaWeapon && BaseOpponent::toOmegaWeapon == false){
        this->setlevel(10);
        this->setgil(999);
        BaseOpponent::toOmegaWeapon = true;
    }
    else {
        opponent->updateKnight(this);
    }
    return BaseKnight::fight(opponent);
}
bool NormalKnight::fight(BaseOpponent *opponent){
    opponent->updateKnight(this);
    return BaseKnight::fight(opponent);
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
ArmyKnights::ArmyKnights(const string &file_armyknights){
    ifstream knightfile(file_armyknights);
        if (knightfile.is_open()) {
            knightfile >> size;
            //cout<<size;
            knight = new BaseKnight*[size];
            for (int i = 0; i < size; i++) {
                
                int hp, level, phoenixdownI, gil, antidote;
               
                knightfile  >> hp >> level >> phoenixdownI >> gil >> antidote;
                knight[i] = BaseKnight::create( i+1,  hp,  level,  gil,  antidote, phoenixdownI);
            }
           
    }
     knightfile.close();
}
bool ArmyKnights::fight(BaseOpponent *opponent){
    while(size){
        BaseKnight *last_knight = lastKnight();
        int tempt = 0;
        if(last_knight->fight(opponent)){
            for(int i = size-1; i>=1; i--){
                tempt = knight[i]->getResidualGil();
                if(tempt == 0 || i == 0) break;
                knight[i-1]->setgil(tempt + knight[i-1]->getgil());
            }
            break;
        }
        size--;
        delete last_knight;
    }
    delete opponent;
    return this->size;
}
//adventure
bool ArmyKnights::adventure (Events * events) {
    bool success = false;
    bool inserted = false;
    
    for(int i = 0; i < events->count() && size != 0; i++) {
        int eventType = events->get(i);
        
        switch(eventType) {
            case 1:
                fight(BaseOpponent::create(i, MadBear));
                
                break;
            case 2:
                fight(BaseOpponent::create(i, Bandit));
                
                break;
            case 3:
                fight(BaseOpponent::create(i, LordLupin));
                
                break;
            case 4:
                fight(BaseOpponent::create(i, Elf));
                
                break;
            case 5:
                fight(BaseOpponent::create(i, Troll));
                
                break;
            case 6:
                fight(BaseOpponent::create(i, Tornbery));
                
                break;
            case 7:
                fight(BaseOpponent::create(i, QueenOfCards));
                
                break;
            case 8:
                fight(BaseOpponent::create(i, NinaDeRings));
                
                break;
            case 9:
                fight(BaseOpponent::create(i, DurianGarden));
                
                break;
            case 10:
                fight(BaseOpponent::create(i, OmegaWeapon));
                
                break;
            case 11:
                fight(BaseOpponent::create(i, Hades));
                if(BaseOpponent::toHades) {
                    PaladinShield = true;
                }
                
                break;
            case 95:
                PaladinShield = true;
                
                break;
            case 96:
                LancelotSpear = true;
                
                break;
            case 97:
                GuinevereHair = true;
                
                break;
            case 98:
                if(LancelotSpear && PaladinShield && GuinevereHair) {
                    ExcaliburSword = true;
                }
                
                break;
            case 112:{

                BaseItem *phoenixII = new PhoenixDownII();
                
                for(int i=size-1; i>=0; i--){
                    if(knight[i]->setBag(phoenixII)) {
                        inserted = true;
                        break;
                    }
                }
                if(!inserted) {
                        delete phoenixII;
                    }
                    
                    break;
                }
            case 113:{
                BaseItem *phoenixIII = new PhoenixDownIII();
                
                for(int i=size-1; i>=0; i--){
                    if(knight[i]->setBag(phoenixIII)) {
                        inserted = true;
                        break;
                    }
                }
                if(!inserted) {
                        delete phoenixIII;
                    }
                    
                    break;
                }
            case 114:{
                BaseItem *phoenixIV = new PhoenixDownIV();
                
                for(int i=size-1; i>=0; i--){
                    if(knight[i]->setBag(phoenixIV)) {
                        inserted = true;
                        break;
                    }
                    
                }
                if(!inserted) {
                        delete phoenixIV;
                    }
                    
                    break;
                }
            case 99:{
                    if(ExcaliburSword) {
                    //printInfo();
                    success = true;
                } 
                else if(!GuinevereHair || !PaladinShield || !LancelotSpear ) {
                    int temp = size;
                    size = 0;
                    //printInfo();
                    size = temp;
                    
                } 
                else {
                    int Hp99 = 5000;
                    BaseKnight *KnightLast = NULL;
                    int kNomal = 0;
                    bool check = false;
                    while(size) {
                        BaseKnight *knightback = lastKnight();
                        Hp99 -= knightback->BaseDamage();
                        if(knightback->BaseDamage() == 0) {
                            kNomal++;
                            if(KnightLast == NULL) {
                                KnightLast = knightback;
                                check = true;
                            }
                        }
                        if(Hp99 <= 0) {
                            size += kNomal;
                            if(KnightLast != NULL) {
                                knight[size - 1] = KnightLast;
                            }
                            //printInfo();
                            size -= kNomal;
                            if(KnightLast != NULL) {
                                delete KnightLast;
                            }
                            success = true;
                            break;
                        }
                        if(check) {
                            check = false;
                        } else {
                            delete knightback;
                        }
                        size--;
                    }
                    if(KnightLast != NULL) {
                        delete KnightLast;
                    }
                    //printInfo();
                }
                break;
            }
    
    if(size == 0) break;
    
    }
    printInfo();
    //cout<<size<<endl;
    }
return success;
}
int ArmyKnights::count() const{
    // int count = 0;
    //     for (int i = 0; i < size; i++) {
    //         if (knights[i]->fight()) {
    //             count++;
    //         }
    //     }
    //     return count;
    return size;
}
BaseKnight * ArmyKnights::lastKnight() const{
    if(size == 0) return NULL;
    else return knight[size-1];
}
bool ArmyKnights::hasPaladinShield() const{
     return PaladinShield;
   
}
bool ArmyKnights::hasLancelotSpear() const{
    return LancelotSpear;
   
}
bool ArmyKnights::hasGuinevereHair() const{
    return GuinevereHair;
}
bool ArmyKnights::hasExcaliburSword() const{
    return ExcaliburSword;
}

Events::Events(string file_events){
    ifstream eventfile(file_events);
        if(eventfile.is_open()){
            eventfile>>size;
            event = new int[size];
            for(int i=0; i<size; i++){
                eventfile>>event[i];
            }
            eventfile.close();
        }
}
//số lượng sk
int Events::count()const {
    return this->size;
}
//mã sk ở vị trí i
int Events::get(int i) const{
    return this->event[i];
}

Events::~Events(){
    delete[] event;
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

/* * * END implementation of class KnightAdventure * * */



