


import os
import numpy as np
from scipy import signal
import sounddevice as sd

def am_decoder(fileName, offset):
    data = np.fromfile(fileName, np.uint8)
    compData = data[::2] + 1j * data[1::2]
    shiftedData = compData - (128 + 1j * 128)
    Fs = 2048000
    dt = 1 / Fs
    t = np.r_[:10:dt]
    centeredData =  shiftedData * np.exp(1j*2*np.pi*(-offset)*t)
    decimatedData = signal.decimate(centeredData, 64, ftype='fir')
    demodedData = np.abs(decimatedData)
    maxValue = np.max(demodedData)
    demodedData = demodedData / maxValue
    demodedData = signal.resample(demodedData, 480000)
    return demodedData

sd.play(am_decoder('rtl_am.dat', -400000), 48000)