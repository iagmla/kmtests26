struct tests {
    uint8_t bigraphs[676][2];
    uint8_t trigraphs[17576][3];
    uint32_t bigraphOccurrences[676];
    uint32_t trigraphOccurrences[17576];
    uint32_t bigraphResults[676];
    uint32_t trigraphResults[17576];
    int period;
    uint32_t sums;
    uint32_t avgSums;
    uint32_t datalen;
};

void testsInit(struct tests *t) {
    memset(t->bigraphResults, 0, 676*sizeof(uint32_t));
    memset(t->bigraphOccurrences, 0, 676*sizeof(uint32_t));
    memset(t->trigraphResults, 0, 17576*sizeof(uint32_t));
    memset(t->trigraphOccurrences, 0, 17576*sizeof(uint32_t));
};

void genBiGraphs(struct tests *t) {
    uint8_t bi[2] = {0};
    int tmp[2] = {0};
    int c = 0;
    int p = 0;
    int l;
    int s = 0;
    for (int i = 0; i < 676; i++) {
        if ((c % 26) == 0) {
            p = (p - 1) % 2;
            if (p < 0) {
                p += 2;
            }
        }
        tmp[0] = s;
        tmp[1] = c;
        bi[0] = (tmp[0] + 65);
        bi[1] = (tmp[1] + 65);
        t->bigraphs[i][0] = bi[0];
        t->bigraphs[i][1] = bi[1];
        c = (c + 1) % 26;
        if (c < 0) {
            c += 26;
        }
        if ((c % 26) == 0) {
            s = (s + 1) % 26;
        }
    }
}

int getBiGraphIndex(struct tests *t, uint8_t *bi) {
    int i = 0;
    for (i = 0; i < 676; i++) {
        if (memcmp(t->bigraphs[i], bi, 2*sizeof(uint8_t)) == 0) {
            break;
        }
    }
    return i;
}

void testBiGraph(struct tests *t, char *inFilename) {
    FILE *infile;
    infile = fopen(inFilename, "rb");
    fseek(infile, 0, SEEK_END);
    uint32_t datalen = ftell(infile);
    t->datalen = datalen;
    fseek(infile, 0, SEEK_SET);
    uint8_t bi[2];
    int index;
    uint32_t blocks = datalen / 2;
    for (int i = 0; i < blocks; i++) {
        fread(bi, 1, 2, infile);
        index = getBiGraphIndex(t, bi);
        t->bigraphOccurrences[index] += 1;
    }
    fclose(infile);
}

void printBiGraph(struct tests *t) {
    uint8_t bi[2] = {0};
    for (int i = 0; i < 676; i++) {
        bi[0] = t->bigraphs[i][0];
        bi[1] = t->bigraphs[i][1];
        if (t->bigraphResults[i] == 1) {
            printf("Bi Graph %s %d FAIL ------\n", bi, t->bigraphOccurrences[i]);
        }
        else {
            printf("Bi Graph %s %d PASS ------\n", bi, t->bigraphOccurrences[i]);
        }
    }
}

void resultsBiGraph(struct tests *t) {
    int expected_max = (t->datalen + (676 * 26 * 5)) / 676 / 2;
    int expected_min = (t->datalen + (676 * 26 * 5)) / 2 / ((676 / 5) + 676);
    for (int i = 0; i < 676; i++) {
        if ((t->bigraphOccurrences[i] >= expected_min) && (t->bigraphOccurrences[i] <= expected_max)) {
            t->bigraphResults[i] = 0;
        }
        else {
            t->bigraphResults[i] = 1;
        }
    }   
}

void runBiGraph(struct tests *t, char *inFilename) {
    genBiGraphs(t);
    testBiGraph(t, inFilename);
    resultsBiGraph(t);
    printBiGraph(t);
}

void genTriGraphs(struct tests *t) {
    uint8_t tri[3] = {0};
    int tmp[3] = {0};
    int c = 0;
    int p = 0;
    int l;
    int s = 0;
    int v = 0;
    for (int i = 0; i < 17576; i++) {
        if (((i % 676) == 0) && (i != 0))  {
            v = (v + 1) % 26;
            if (v < 0) {
                v += 26;
            }
        }
        tmp[0] = v;
        tmp[1] = s;
        tmp[2] = c;
        tri[0] = (tmp[0] + 65);
        tri[1] = (tmp[1] + 65);
        tri[2] = (tmp[2] + 65);
        t->trigraphs[i][0] = tri[0];
        t->trigraphs[i][1] = tri[1];
        t->trigraphs[i][2] = tri[2];
        c = (c + 1) % 26;
        if (c < 0) {
            c += 26;
        }
        if ((c % 26) == 0) {
            s = (s + 1) % 26;
            if (s < 0) {
                s += 26;
            }
        }
    }
}

int getTriGraphIndex(struct tests *t, uint8_t *tri) {
    int i = 0;
    for (i = 0; i < 17576; i++) {
        if (memcmp(t->trigraphs[i], tri, 3*sizeof(uint8_t)) == 0) {
            break;
        }
    }
    return i;
}

void testTriGraph(struct tests *t, char *inFilename) {
    FILE *infile;
    infile = fopen(inFilename, "rb");
    fseek(infile, 0, SEEK_END);
    uint32_t datalen = ftell(infile);
    t->datalen = datalen;
    fseek(infile, 0, SEEK_SET);
    uint8_t tri[3];
    int index;
    uint32_t blocks = datalen / 3;
    for (int i = 0; i < blocks; i++) {
        fread(tri, 1, 3, infile);
        index = getTriGraphIndex(t, tri);
        t->trigraphOccurrences[index] += 1;
    }
    fclose(infile);
}

void printTriGraphs(struct tests *t) {
    uint8_t tri[3] = {0};
    for (int i = 0; i < 17576; i++) {
        tri[0] = t->trigraphs[i][0];
        tri[1] = t->trigraphs[i][1];
        tri[2] = t->trigraphs[i][2];
        if (t->trigraphResults[i] == 1) {
            printf("Tri Graph %s %d FAIL ------\n", tri, t->trigraphOccurrences[i]);
        }
        else {
            printf("Tri Graph %s %d PASS ------\n", tri, t->trigraphOccurrences[i]);
        }
    }
}

void resultsTriGraph(struct tests *t) {
    int expected_max = (t->datalen + (17576 * 26 * 2)) / 17576 / 3;
    int expected_min = (t->datalen + (17576 * 1 * 1)) / 3 / ((17576 / 2) + 17576);
    for (int i = 0; i < 676; i++) {
        if ((t->trigraphOccurrences[i] >= expected_min) && (t->trigraphOccurrences[i] <= expected_max)) {
            t->trigraphResults[i] = 0;
        }
        else {
            t->trigraphResults[i] = 1;
        }
    }
}

void runTriGraph(struct tests *t, char *inFilename) {
    genTriGraphs(t);
    testTriGraph(t, inFilename);
    resultsTriGraph(t);
    printTriGraphs(t);
}

void testPeriod(struct tests *t, char *inFilename, int runLength) {
    FILE *infile;
    infile = fopen(inFilename, "rb");
    fseek(infile, 0, SEEK_END);
    uint32_t datalen = ftell(infile);
    t->datalen = datalen;
    fseek(infile, 0, SEEK_SET);
    uint32_t runs = datalen / runLength;
    uint32_t offset = 0;
    for (uint32_t x = 0; x < runs; x++) {
        fseek(infile, offset, 0);
        uint8_t run[runLength];
        uint8_t sample[runLength];
        fread(run, 1, runLength, infile);
        for (uint32_t y = 0; y < runs; y++) {
            fread(sample, 1, runLength, infile);
            if (memcmp(run, sample, runLength*sizeof(uint8_t)) == 0) {
                t->period += 1;
            }
        }
        offset += runLength;
        runs -= runLength;
    }
    fclose(infile);
}

void printPeriod(struct tests *t) {
    int threshold = sqrt(sqrt(sqrt(t->datalen)));
    if (t->period <= threshold) {
        printf("Period %d PASS ------\n", t->period);
    }
    else {
        printf("Period %d FAIL ------\n", t->period);
    }
}

void runPeriod(struct tests *t, char *inFilename) {
    int maxRun = 13;
    int minRun = 8;
    for (int i = maxRun; i != minRun - 1; i--) {
        testPeriod(t, inFilename, i);
    }
    printPeriod(t);
}

void printSums(struct tests *t) {
    uint32_t sqrtSums = sqrt(t->datalen);
    uint32_t gap = sqrtSums / 4;
    uint32_t threshold = sqrtSums + gap;
    if (t->sums <= threshold) {
        printf("Sums %d PASS ------\n", t->sums);
    }
    else {
        printf("Sums %d FAIL ------\n", t->sums);
    }
}

void printavgSums(struct tests *t) {
    int max = ((26 * 26) / 2) - 13;
    int min = (((26 * 26) / 2) - 13) - 5;
    if ((t->avgSums <= max) || (t->avgSums >= min)) {
        printf("AvgSums %d PASS ------\n", t->avgSums);
    }
    else {
        printf("AvgSums %d FAIL ------\n", t->avgSums);
    }
}

void runSums(struct tests *t, char *inFilename) {
    int blockLength = 26;
    int max = ((26 * 26) / 2) + (26 * 5);
    int min = (((26 * 26) / 2) - (26 * 5));
    FILE *infile;
    infile = fopen(inFilename, "rb");
    fseek(infile, 0, SEEK_END);
    uint32_t datalen = ftell(infile);
    fseek(infile, 0, SEEK_SET);
    uint8_t block[26];
    int index;
    t->datalen = datalen;
    uint32_t blocks = datalen / blockLength;
    t->sums = 0;
    t->avgSums = 0;
    for (uint32_t i = 0; i < blocks; i++) {
        fread(block, 1, blockLength, infile);
        int blockSum = 0;
        for (int x = 0; x < blockLength; x++) {
            blockSum += (block[x] - 65);
        }
        if ((blockSum > max) || (blockSum < min)) {
            t->sums += 1;
        }
        t->avgSums += blockSum;
    }
    fclose(infile);
    t->avgSums = t->avgSums / (datalen / blockLength);
    printSums(t);
    printavgSums(t);
}
