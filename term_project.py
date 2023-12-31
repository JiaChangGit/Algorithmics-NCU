# -*- coding: utf-8 -*-
"""Term project.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/19IX8ic6rZboB-rnntNOukttGTTSdocT1
"""

!pip install qiskit
from qiskit import IBMQ, Aer
from qiskit import QuantumCircuit, execute
from qiskit.visualization import plot_histogram

def Deutsch_Oracle(qc,oracle_type):
    if oracle_type == 1: #Constant-0函數
        qc.id(1) 
    if oracle_type == 2: #Constant-1函數
        qc.x(1)
    if oracle_type == 3: #Identity函數
        qc.cx(0,1)
    if oracle_type == 4: #Not函數
        qc.x(0)
        qc.cx(0, 1)
        qc.x(0)
qc = QuantumCircuit(2, 1)
qc.x(1)
qc.h(0)
qc.h(1)
qc.barrier()
oracle_type = 1
Deutsch_Oracle(qc, oracle_type)
qc.barrier()
qc.h(0)
qc.measure(0, 0)
qc.draw()

sim = Aer.get_backend('aer_simulator')
job = execute(qc, sim, shots=1000)
result = job.result()
counts = result.get_counts()
plot_histogram(counts)

def Deutsch_Oracle(qc,oracle_type):
    if oracle_type == 1: #Constant-0函數
        qc.id(1) 
    if oracle_type == 2: #Constant-1函數
        qc.x(1)
    if oracle_type == 3: #Identity函數
        qc.cx(0,1)
    if oracle_type == 4: #Not函數
        qc.x(0)
        qc.cx(0, 1)
        qc.x(0)
qc = QuantumCircuit(2, 1)
qc.x(1)
qc.h(0)
qc.h(1)
qc.barrier()
oracle_type = 2
Deutsch_Oracle(qc, oracle_type)
qc.barrier()
qc.h(0)
qc.measure(0, 0)
qc.draw()

sim = Aer.get_backend('aer_simulator')
job = execute(qc, sim, shots=1000)
result = job.result()
counts = result.get_counts()
plot_histogram(counts)

def Deutsch_Oracle(qc,oracle_type):
    if oracle_type == 1: #Constant-0函數
        qc.id(1) 
    if oracle_type == 2: #Constant-1函數
        qc.x(1)
    if oracle_type == 3: #Identity函數
        qc.cx(0,1)
    if oracle_type == 4: #Not函數
        qc.x(0)
        qc.cx(0, 1)
        qc.x(0)
qc = QuantumCircuit(2, 1)
qc.x(1)
qc.h(0)
qc.h(1)
qc.barrier()
oracle_type = 3
Deutsch_Oracle(qc, oracle_type)
qc.barrier()
qc.h(0)
qc.measure(0, 0)
qc.draw()

sim = Aer.get_backend('aer_simulator')
job = execute(qc, sim, shots=1000)
result = job.result()
counts = result.get_counts()
plot_histogram(counts)

def Deutsch_Oracle(qc,oracle_type):
    if oracle_type == 1: #Constant-0函數
        qc.id(1) 
    if oracle_type == 2: #Constant-1函數
        qc.x(1)
    if oracle_type == 3: #Identity函數
        qc.cx(0,1)
    if oracle_type == 4: #Not函數
        qc.x(0)
        qc.cx(0, 1)
        qc.x(0)
qc = QuantumCircuit(2, 1)
qc.x(1)
qc.h(0)
qc.h(1)
qc.barrier()
oracle_type = 4
Deutsch_Oracle(qc, oracle_type)
qc.barrier()
qc.h(0)
qc.measure(0, 0)
qc.draw()

sim = Aer.get_backend('aer_simulator')
job = execute(qc, sim, shots=1000)
result = job.result()
counts = result.get_counts()
plot_histogram(counts)