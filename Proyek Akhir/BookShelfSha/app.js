// Menampilkan buku ketika selesai memuat
document.addEventListener("DOMContentLoaded", () => {
    // Load data dari localStorage jika ada
    if (localStorage.getItem('books')) {
        books = JSON.parse(localStorage.getItem('books'));
    }

    displayBooks();
});

// localStorage updater
function updateLocalStorage() {
    localStorage.setItem('books', JSON.stringify(books));
}

// Membuat objek array yang berisi buku
let books = [];

// Menampilkan buku di rak
function displayBooks(booksToDisplay = books) {
    const belumBaca = document.getElementById('belumBaca');
    const dahBaca = document.getElementById('dahBaca');
    belumBaca.innerHTML = '';
    dahBaca.innerHTML = '';
 
    booksToDisplay.forEach(book => {
        const bookItem = document.createElement('div');
        bookItem.classList.add('book');
        bookItem.textContent = `${book.title} oleh ${book.author} terbitan ${book.year}`;
        
        // +tombol remove
        const removeButton = document.createElement('button');
        removeButton.className = 'removeBtn';
        removeButton.innerHTML = '<i class="fa-solid fa-trash"></i>';
        removeButton.addEventListener('click', () => removeBook(book.id));
    
        // +checkbox complete
        const checkBox = document.createElement('input');
        checkBox.type = 'checkbox';
        checkBox.checked = book.isComplete;
        checkBox.classList.add('checkBox');
        checkBox.addEventListener('change', () => {
            book.isComplete = checkBox.checked;
            displayBooks();
        });
    
        // +div untuk bookStatus
        const bookStatus = document.createElement('div');
        bookStatus.classList.add('bookStatus');
        bookStatus.appendChild(removeButton);
        bookStatus.appendChild(checkBox);
    
        // Menambahkan bookStatus ke bookItem
        bookItem.appendChild(bookStatus);
    
        if (book.isComplete) {
            dahBaca.appendChild(bookItem);
        } else {
            belumBaca.appendChild(bookItem);
        }
    });

    updateLocalStorage();    
}

// Menghapus buku dari rak
function removeBook(bookId) {    
    const deleteDialog = document.getElementById('deleteDialog');
    const cancelButton = document.getElementById('cancelDelete');
    const confirmButton = document.getElementById('confirmDelete');

    deleteDialog.showModal();

    cancelButton.addEventListener('click', () => {
        deleteDialog.close();
    });

    confirmButton.addEventListener('click', () => {
        books = books.filter(book => book.id !== bookId)
        deleteDialog.close();
        displayBooks();
        updateLocalStorage();
    });
}

// Menambahkan buku ke rak
function addBook() {
    const titleInput = document.getElementById('title');
    const authorInput = document.getElementById('author');
    const yearInput = document.getElementById('year');
    const isCompleteCheckbox = document.getElementById('isComplete');

    const title = titleInput.value;
    const author = authorInput.value;
    const year = parseInt(yearInput.value);
    const isComplete = isCompleteCheckbox.checked;


    if (title && author && !isNaN(year) && year > 0) {
        const newBook = { id: Date.now(), title, author, year, isComplete};
        books.push(newBook);
        displayBooks();
        
        titleInput.value = '';
        authorInput.value = '';
        yearInput.value = '';
        isCompleteCheckbox.checked = false;
        updateLocalStorage();
    } 
    else {
        alert('Tolong masukkan judul, penulis, dan tahun buku yang valid.');
    }
}

// Mencari buku dari rak
function searchBook() {
    const searchInput = document.getElementById('searchInput').value.toLowerCase();

    const filteredBooks = books.filter(book =>
        book.title.toLowerCase().includes(searchInput) ||
        book.author.toLowerCase().includes(searchInput) ||
        book.year.toString().includes(searchInput)
    );

    displayBooks(filteredBooks);
}
