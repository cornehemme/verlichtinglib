# koplamp

## objects
### koplamp
2 lampjes die om de beurt knipperen afgewisseld door tegelijk knipperen. Door bij elk object een andere startdelay in te voeren kan voorkomen worden dat alle objects tegelijk knipperen
### zwaailamp
simpel knipperent lampje met een bepaalde delay

## standaard opmaak:
```
#include <verlichting.h>

// create objects 
koplamp "NAME1"("LEDPIN1", "LEDPIN2", "STARTDELAY"); // ledpin 1, ledpin 2, start delay
koplamp "NAME2"("LEDPIN1", "LEDPIN2", "STARTDELAY"); // ledpin 1, ledpin 2, start delay
...........
...........


zwaailamp "NAME3"("LEDPIN","BLINKDELAY"); // ledpin, delay
zwaailamp "NAME4"("LEDPIN","BLINKDELAY"); // ledpin, delay
...........
...........


void setup() {

}

void loop() {
  // call all the objects to update
  "NAME1".update();
  "NAME2".update();
  "NAME3".update();
  ...........
  ...........

}
```
