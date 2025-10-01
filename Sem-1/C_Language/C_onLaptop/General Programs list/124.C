/* 124. An election is contested by 5 candidates. The candidates are numbered 1 to 5 and the voting is done by marking the candidate number on the ballot paper. Write a program in C to read the ballots and count the votes cast for each candidate using an array variable count. In case a number read is outside the range 1 to 5, the ballot should be considered as a spoilt ballot and the program should also count the number of spoilt ballots. */

#include<stdio.h>
#include<conio.h>

int main() {
	int votes[5] = { 0 }, vote, i, spoilt = 0, total = 0;
	// clrscr();
	printf("\n\tEnter votes (1 to 5). Enter 0 to stop voting:\n");
	while (1) {
		printf("\tVote: ");
		scanf("%d", &vote);
		if (vote == 0) {
			break;
		}
		else if (vote >= 1 && vote <= 5) {
			votes[vote - 1]++;
			total++;
		}
		else {
			spoilt++;
		}
	}
	printf("\n\tVote count:\n");
	for (i = 0; i < 5; i++) {
		printf("\tCandidate %d: %d votes\n", i + 1, votes[i]);
	}
	printf("\tSpoilt ballots: %d\n", spoilt);
	printf("\tTotal valid votes: %d\n", total);

	// getch();
	return 0;
}