#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T isi, priority;
  Element *lanjut;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head, tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> qNew;
  qNew.head = nullptr;
  qNew.tail = nullptr;
  return qNew;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> pNew = new Element<T>;
  pNew -> isi = value;
  pNew -> priority = priority;
  pNew -> lanjut = nullptr;

  if(q.head == nullptr && q.tail == nullptr) 
  {
    q.head = pNew;
    q.tail = pNew;
  } 
  else 
  {
    ElementPtr<T> curr = q.head;
    ElementPtr<T> pRev = nullptr;
    while(pNew -> priority <= curr -> priority) 
    {
      if(curr->lanjut == nullptr) 
        break;
      pRev = curr;
      curr = curr -> lanjut;
    } 
    
    // Insert First
    if(curr == q.head && pNew -> priority > curr -> priority) 
    {
      pNew -> lanjut = curr;
      q.head = pNew;
    } 
    // Insert Last
    else if(curr == q.tail && pNew -> priority < curr -> priority) 
    {
      curr -> lanjut = pNew;
      q.tail = pNew;
    } 
    // Insert Middle
    else 
    {
      pRev -> lanjut = pNew;
      pNew -> lanjut = curr;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head -> isi;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> qDel;
  if(q.head == nullptr && q.tail == nullptr) {
    qDel = nullptr;
  } else if(q.head -> lanjut == nullptr) {
    qDel = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  } else {
    qDel = q.head;
    q.head = q.head -> lanjut;
    qDel -> lanjut = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
