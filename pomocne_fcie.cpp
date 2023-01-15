#pragma once

#include "pomocne_fcie.h"

int index_dna(QString den)
{
	if (den == "Pondelok") return 0;
	else if (den == "Utorok") return 1;
	else if (den == "Streda") return 2;
	else if (den == "Stvrtok") return 3;
	else if (den == "Piatok") return 4;
	else if (den == "Sobota") return 5;
	else if (den == "Nedela") return 6;
	return -1;
}