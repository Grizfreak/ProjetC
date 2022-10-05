#include "../headers/mob.h"
void freeMobs(Mob **mobs, int nbMobs)
{
    for (int i = 0; i < nbMobs; i++)
    {
        if (mobs[i] != NULL)
        {
            free(mobs[i]);
            mobs[i] = NULL;
        }
    }
    free(mobs);
}