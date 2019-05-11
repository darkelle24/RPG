/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fc_for_compt
*/

#ifndef FC_FOR_COMPT_H_
    #define FC_FOR_COMPT_H_

    #include "proto/proto.h"

    int ap(fight_t *fight, char *str, int target);
    int ad(fight_t *fight, char *str, int target);
    int missing_hp(fight_t *fight, char *str, int target);

    const char *flag_name[] = {
        "*AP",
        "*AD",
        "*missing_hp",
        NULL
    };

    int (* const fonction_flag[])(fight_t *, char *str, int target) = {
        &ap,
        &ad,
        &missing_hp,
        NULL
    };

    const char *spe_name[] = {
        NULL
    };

    void (* const fonction_spe[])(fight_t *, char *str, int target) = {
        NULL
    };

#endif /* !FC_FOR_COMPT_H_ */