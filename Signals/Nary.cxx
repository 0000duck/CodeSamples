#include <iostream>
#include <algorithm>
#include <Signals/Signals.hxx>
#include <Signals/BoostSlots.hxx>
using namespace std;

class Signal : public SignalBase
{
  public:
    struct VoidSignal;

    typedef fusion::map <
      fusion::pair <VoidSignal, BOOST_SIGNAL(void())>
      > SignalsMap;
#include <Signals/SignalMacros.hxx>

  public:
    Signal() { 
      fusion::for_each(m_signals, initialize());
    }
};

struct Slot 
{
  Slot() { }

  virtual void voidSlot () { cout << "Slot::voidSlot" << endl; }
};

struct SlotDerived : public Slot
{
  SlotDerived() { }

  virtual void voidSlot () { cout << "SlotDerived::voidSlot" << endl; }
};

int main (void)
{
  cout << "--------------------------------" << endl;

  Signal sig;
  Slot* slot = new SlotDerived();
  sig.signal<Signal::VoidSignal>().connect(MEM_FUN_OBJ_PTR (Slot,voidSlot,slot,0));

  sig.emitSignal<Signal::VoidSignal>();

  cout << "--------------------------------" << endl;
}
