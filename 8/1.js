let arrayInitial = [54, 31, 72, 62, 5, 95, 7, 64, 59, 87, 63, 64];
let sortedArray = [];
let max = Math.max.apply(null, arrayInitial) + 1;

function print(array) {
    console.log();
    for (let i = 0; i < array.length; i++) {
        if (array[i] === max) {
            process.stdout.write("WIN ");
        } else {
            process.stdout.write(JSON.stringify(array[i]) + " ");
        }
    }
}

function tour(array, length) {
    let tourArray = [];
    print(array);
    let lengthTourArr = Math.ceil(length / 2);
    let win;

    if (length === 3) {
        tourArray[0] = Math.min(array[0], array[1]);
        tourArray[1] = array[2];

        print(tourArray);
        tourArray = Math.min(tourArray[0], tourArray[1]);

        win = tour(tourArray, lengthTourArr);
        process.stdout.write(JSON.stringify(win));
        arrayInitial[arrayInitial.indexOf(win)] = max;
        return win;
    } else {
        if (lengthTourArr === 1) {
            return array;
        }

        for (let i = 0, j = 0; j < lengthTourArr; i += 2, j++) {
            if (array[i] < array[i + 1]) {
                tourArray[j] = array[i];
            } else {
                tourArray[j] = array[i + 1];
            }
        }

        win = tour(tourArray, lengthTourArr);

        return win;
    }
}

function tournamentSort(array) {
    for (let i = 0; i < array.length; i++) {
        console.log(`\nTour ${i + 1} : `);
        sortedArray[i] = tour(array, array.length);
        console.log();
    }

    process.stdout.write("\nSorted array : ");
    sortedArray.forEach((item) => {
        process.stdout.write(JSON.stringify(item) + " ");
    });
}

tournamentSort(arrayInitial);
