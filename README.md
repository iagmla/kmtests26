# kmtests26

kmtests26 is a statistical program by KryptoMagick to test random A-Z ASCII datasets.  It's meant to aid the testing of A-Z ciphers and cryptanalysis.

*** For use with A-Z ASCII datasets only!!!

*** This project is under construction.

# Usage

kmtests26 <filename> > output.file


# Uniformly Random A-Z Data

Uniformly random A-Z data should appear similar to the following output.  The KEG playing card cipher was used as a model ideal cipher.  Below is data from 1 million A's being encrypted by a single key.

Value  Occurrences  Fractions  Probabilitiy

  0         38324  0.038324   0.996424

  1         38599  0.038599   1.003574

  2         38474  0.038474   1.000324

  3         38338  0.038338   0.996788

  4         38569  0.038569   1.002794

  5         38609  0.038609   1.003834

  6         38451  0.038451   0.999726

  7         38670  0.038670   1.005420

  8         38131  0.038131   0.991406

  9         38462  0.038462   1.000012

 10         38430  0.038430   0.999180

 11         38328  0.038328   0.996528

 12         38788  0.038788   1.008488

 13         38267  0.038267   0.994942

 14         38432  0.038432   0.999232

 15         38425  0.038425   0.999050

 16         38329  0.038329   0.996554

 17         38809  0.038809   1.009034

 18         38698  0.038698   1.006148

 19         38470  0.038470   1.000220

 20         38275  0.038275   0.995150

 21         38531  0.038531   1.001806

 22         38230  0.038230   0.993980

 23         38549  0.038549   1.002274

 24         38327  0.038327   0.996502

 25         38485  0.038485   1.000610

Entropy 4.700426

Average 12.498564

IC 25.999836

Serial Correlation 0.000059

Chi-Squared Distribution 24.946409

# Acceptable Test Failures

The KEG Stream Cipher and A-Z output from /dev/urandom were compared and showed the same amount of test failures.  An example of acceptable number of test failures for a 1 million letter output is below:

Bi Graph DY 656 FAIL ------

Bi Graph NI 652 FAIL ------

Bi Graph RY 811 FAIL ------

Bi Graph SC 818 FAIL ------

Bi Graph UT 643 FAIL ------

Bi Graph VS 655 FAIL ------

Bi Graph XS 820 FAIL ------

Tri Graph ABV 8 FAIL ------

Tri Graph ACE 11 FAIL ------

Tri Graph ACF 8 FAIL ------

Tri Graph ACR 8 FAIL ------

Tri Graph ACW 9 FAIL ------

Tri Graph ADJ 8 FAIL ------

Tri Graph ADY 11 FAIL ------

Tri Graph AFE 10 FAIL ------

Tri Graph AGJ 9 FAIL ------

Tri Graph AHD 11 FAIL ------

Tri Graph AIM 11 FAIL ------

Tri Graph AJC 10 FAIL ------

Tri Graph AJO 11 FAIL ------

Tri Graph ALM 11 FAIL ------

Tri Graph AOF 9 FAIL ------

Tri Graph APV 11 FAIL ------

Tri Graph AQU 10 FAIL ------

Tri Graph ARF 11 FAIL ------

Tri Graph ARY 10 FAIL ------

Tri Graph ATC 11 FAIL ------

Tri Graph AUK 11 FAIL ------

Tri Graph AVN 10 FAIL ------

Tri Graph AVT 9 FAIL ------

Tri Graph AVV 9 FAIL ------

Tri Graph AWU 7 FAIL ------
