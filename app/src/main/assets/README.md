# System Sizer II – Water Softener Estimator

**Version:** 20250728  
**Author:** [N. T. Crotser](https://github.com/crotsertech)  
**License:** GNU GPL v3  
**Live Demo:** _[HERE](https://crotser.us/ss2.html)_  

---

## 💧 What is System Sizer II?

**System Sizer II** is a free and open-source web-based tool designed to estimate the correct water softener size based on real-world parameters:

- Water hardness (gpg)
- Iron (ppm)
- Manganese (ppm)
- Number of people in the home
- Use of **Ecosoft ECOMIX C** media

It uses EPA 2025 estimates (82 gallons/day/person) and adjusts for iron and manganese content to recommend:

- **Resin volume (cu ft)**
- **Softener capacity (grains)**
- **Estimated gallons between regenerations**

---

## ⚠️ Important Notice

> In order to use this program, you **must** have a **current water analysis** that includes hardness, iron, and manganese levels.

This estimator is intended for homeowners, installers, and water treatment professionals who need a quick sizing recommendation based on actual water quality.

---

## 🚀 Features

- Mobile-responsive design
- Calculates demand and compensates for contaminants
- Supports ECOMIX-specific adjustments
- User-friendly error handling
- Licensed under GNU GPL v3
- No internet access required once hosted locally

---

## 🛠️ How to Use

1. Clone or download this repo.
2. Open `ss2.html` in any modern browser.
3. Fill in your water test values and household size.
4. Click **Calculate** to see results.

---

## 📦 Installation

No installation necessary. Just open the HTML file directly in a browser.


```bash
git clone https://github.com/crotsertech/System-Sizer-II-for-Web.git
cd System-Sizer-II-for-Web
# Host with any web server or open ss2.html locally
