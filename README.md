# Master thesis - Method for Mapping Bisulfite-treated Sequencing Reads To a Genome

## Overview ##

This is full code part of master thesis for Faculty of Electrical Engineering and Computing.
Goal was to develop method for mapping bisulfite-treated sequencing reads to a genome using some of already existing mapping tools.
The work is based on Accel-align tool: https://github.com/raja-appuswamy/accel-align-release

## Get started ##
## Pre-requirement

Since BisulfiteAligner uses Accel-align under-the-hood, there is TBB dependency

#### Intel TBB ####

- source: https://github.com/01org/tbb/releases/tag/2019_U5
- libtbb-dev package

### Installation ###

* clone (git clone --recursive https://github.com/skosier/diplomski-fer)
* Build it: `make`

### Build index ###

It's mandatory to build the index before alignment. Options:

```
-l INT the length of k-mers [32]
```

Example:

```
path-to-bisulfite-aligner/bsfindex -l 32 path-to-ref/ref.fna
```

It will generate two indices aside the reference genome as `path-to-ref/ref.fna.ct_hash` and `path-to-ref/ref.fna.ga_hash`.

### Align ###

When the alignment is triggered, the index will be loaded in memory automatically.

Options:

```
   -t INT number of cpu threads to use [1].
   -l INT length of seed [32].
   -o name of output file to use.
   -x alignment-free.
   -w use WFA for extension. It's using KSW by default.
   -p the maximum distance allowed between the paired-end reads [1000].
   -d disable embedding, extend all candidates from seeding (this mode is super slow, only for benchmark).
   Note: maximum read length and read name length supported are 512.
```

### Pair-end alignment ###

``` 
path-to-bisulfite-aligner/bsfalign options ref.fna read1.fastq read2.fastq
```

Example:

``` 
path-to-bisulfite-align/bsfalign -l 32 -t 4 -o output-path/out.sam \
path-to-ref/ref.fna input-path/read1.fastq input-path/read2.fastq
``` 

### Single-end alignment ###

``` 
path-to-bisulfite-aligner/bsfalign options ref.fna read.fastq
```

Example:

``` 
path-to-bisulfite-aligner/bsfalign -l 32 -t 4 -o output-path/out.sam \
path-to-ref/ref.fna input-path/read.fastq
``` 

### Reference to Accel-align ###
Paper about Accel-align can be found here https://doi.org/10.1186/s12859-021-04162-z :

> Yan, Y., Chaturvedi, N. & Appuswamy, R. 
> Accel-Align: a fast sequence mapper and aligner based on the seed–embed–extend method. 
> BMC Bioinformatics 22, 257 (2021).
