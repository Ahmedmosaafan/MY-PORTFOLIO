<div align="center">

# 🔧 Industrial Spare-Parts Catalog & Lookup System

### A mobile-first, bilingual digital catalog that cuts maintenance search time on the factory floor

![Platform](https://img.shields.io/badge/Platform-iOS%20%7C%20Android-blue)
![Built With](https://img.shields.io/badge/Built%20With-Google%20AppSheet-4285F4)
![Database](https://img.shields.io/badge/Database-Microsoft%20Excel-217346)
![Storage](https://img.shields.io/badge/Asset%20Storage-Google%20Drive-FBBC04)
![Status](https://img.shields.io/badge/Status-Deployed-success)

**Author:** Ahmed M. Saafan, B.Sc. Mechatronics Engineering, Fayoum University (Class of 2026)
**Context:** Industrial Maintenance & Automation Internship (2 months), Edita Food Industries
**Portfolio path:** `MY-PORTFOLIO / 06_Industrial_Digitalization`

</div>

---

## 📑 Table of Contents

1. [Executive Overview](#-executive-overview)
2. [The Problem: A Shop-Floor Bottleneck](#-the-problem-a-shop-floor-bottleneck)
3. [The Solution](#-the-solution)
4. [Live Demo](#-live-demo)
5. [Key Features](#-key-features)
6. [User Workflow (Step by Step)](#-user-workflow-step-by-step)
7. [System Architecture](#-system-architecture)
8. [Data Schema](#-data-schema)
9. [Key Engineering Decisions](#-key-engineering-decisions)
10. [Operational Impact](#-operational-impact)
11. [Skills Demonstrated](#-skills-demonstrated)
12. [Confidentiality Disclaimer](#-confidentiality-disclaimer)

---

## 🎯 Executive Overview

During my 2-month Industrial Maintenance & Automation internship at **Edita Food Industries**, I independently designed, built, and deployed a **mobile Spare-Parts Catalog Application** for maintenance technicians.

The tool replaces manual logs and scattered records with a single searchable, photo-backed, bilingual (English/Arabic) catalog that works on any phone, including inside production halls with weak network coverage.

> **In one sentence:** I turned an unstructured, paper-and-memory-dependent spare-parts lookup into a structured, searchable, mobile-first digital system, designed, built, and deployed end to end as a solo intern project.

| | |
|---|---|
| **Role** | Sole designer, developer, and deployer |
| **Duration** | 2-month internship |
| **Domain** | Industrial maintenance, digitalization, CMMS-adjacent tooling |
| **Approach** | Low-code, 3-tier architecture, rapid iteration with end users |

---

## 🚨 The Problem: A Shop-Floor Bottleneck

During **urgent machine breakdowns** and **preventive maintenance shifts**, technicians lost valuable time on a task that should take seconds: *identifying the right spare part.*

- Part specifications, models, and warehouse locations lived in **manual logs and scattered records**.
- Verifying a single component meant **searching across multiple sources** while a machine sat idle.
- Without a visual reference, there was a real risk of **selecting or installing the wrong part**.
- Knowledge about parts was spread across people and paper rather than in one shared, searchable place.

**Result:** unnecessary downtime during the moments when speed matters most.

---

## 💡 The Solution

A **mobile-first Spare-Parts Catalog Application** built around one design goal: **get a technician from "what part do I need?" to a verified answer in under 5 seconds, on the shop floor, with one hand.**

Every design choice (search-first UI, photo verification, bilingual labels, offline caching, quick-add entry) follows from observing how technicians actually work during a breakdown.

---

## 🎬 Live Demo

<div align="center">

<video src="https://github.com/Ahmedmosaafan/MY-PORTFOLIO/raw/main/06_Industrial_Digitalization/assets/spare_parts_app_demo.mp4" controls muted width="320"></video>

*Short walkthrough: search → open item → verify photo → add / edit a part.*

**[▶ Open the demo video directly](https://github.com/Ahmedmosaafan/MY-PORTFOLIO/raw/main/06_Industrial_Digitalization/assets/spare_parts_app_demo.mp4)**

</div>

---

## ✨ Key Features

| Feature | What it does | Why it matters |
|---|---|---|
| ⚡ **Sub-5-Second Lookup** | Instant search plus multi-criteria filtering by component name, technical description, or subsystem category (**Sensors, Pneumatics, Temperature Controllers, Valves, Motors, PLC Modules**) | Minimizes time spent searching during breakdowns |
| 🖼️ **Visual Verification** | A reference photo, taken on the floor, is attached to every component entry | Prevents wrong-part selection and installation errors |
| 🌐 **Bilingual Records (EN / AR)** | Every field is labeled in English and Arabic, and each part carries both an English and an Arabic name | Usable by the whole maintenance crew, not only English readers |
| ➕ **Field Data Entry** | Quick-add workflow via the **`+`** button lets authorized engineers and technicians add parts straight from their phone, with real-time cloud synchronization | The catalog stays current without a separate admin step |
| ✏️ **In-App Editing** | Any field of an existing part can be corrected from its detail screen, including retaking the photo | Errors are fixed at the source, immediately |
| 🧾 **Source Traceability** | Each record stores the manufacturer catalog file and page it was derived from | Every entry can be audited back to its documentation |
| ✅ **Mandatory-Field Validation** | Item Code and Image are required before a record can be saved | Prevents incomplete, unverifiable entries |
| 📶 **Offline Caching** | Part photos and details are cached for use in areas with weak connectivity | Reliable access inside production halls |

---

## 📱 User Workflow (Step by Step)

### Step 1: Browse, Search & Filter the Catalog

The main catalog presents every component as a photo card grid, so parts are recognized at a glance. Technicians use the search icon or filter by category. The **`+` button** (highlighted) is the entry point for adding new parts in the field.

<div align="center">

<img src="./assets/spare_parts_catalog_marked.png" alt="Main catalog grid view with the + button highlighted" width="300"/>

*Main catalog grid view. The highlighted `+` button opens the quick-add workflow.*

</div>

---

### Step 2: Open the Item Detail View & Verify the Part

Selecting a card opens the detail view: reference photo, English and Arabic part name, item code, technical description, category, and the source catalog page. The technician can visually confirm the part *before* heading to the warehouse or installing it. The highlighted button lets authorized users edit any field.

<div align="center">

<img src="./assets/item_details_marked_.png" alt="Item detail view with edit button highlighted" width="300"/>

*Item detail view (identifiers redacted for confidentiality).*

</div>

---

### Step 3: Add a New Part from the Field

Authorized users tap **`+`** to open a streamlined form. **Item Code** and **Image** are mandatory. The camera button captures the part photo on the spot, and **Save** syncs the record to the cloud so every technician sees it.

<div align="center">

<img src="./assets/add_form_marked.png" alt="Add new item form with required fields" width="300"/>

*Add New Item form with required-field validation and in-app camera capture.*

</div>

---

### Step 4: Edit or Correct an Existing Part

From the detail view, the edit action reopens the same form pre-filled. Any field can be amended and the photo can be removed or retaken. **Save** applies the changes across the shared catalog.

<div align="center">

<img src="./assets/edit_form_marked.png" alt="Edit item form with photo retake" width="300"/>

*Edit mode: change any field, retake or remove the photo, then save.*

</div>

---

### Workflow at a Glance

```
 Breakdown / PM task
        │
        ▼
 ┌──────────────┐    ┌────────────────┐    ┌────────────────────┐
 │ Search or    │───▶│ Open item      │───▶│ Verify photo +     │
 │ filter by    │    │ detail view    │    │ description +      │
 │ category     │    │                │    │ source page        │
 └──────────────┘    └────────────────┘    └─────────┬──────────┘
                                                      │
                          Part not listed /           ▼
                          data incorrect?      Retrieve & install
                     ┌────────────────────┐    the correct part
                     │ "+" add new part   │
                     │ or ✏️ edit entry   │
                     │ (auto-synced)      │
                     └────────────────────┘
```

---

## 🏗️ System Architecture

The system follows a clean **3-tier architecture**, with each tier chosen to be maintainable by plant personnel without specialized development skills.

| Tier | Layer | Technology | Responsibility |
|:---:|---|---|---|
| **1** | **Presentation / Mobile UI** | **Google AppSheet** (cross-platform iOS/Android no-code interface) | Search, filtering, detail views, add/edit forms, camera capture, offline cache |
| **2** | **Database Engine** | **Microsoft Excel** (structured relational tables) | Stores part records: code, bilingual names, description, category, source, image reference |
| **3** | **Asset Storage** | **Google Drive** (indexed image repository) | Hosts component reference photos |

```
┌─────────────────────────────────────────────────────────────┐
│  TIER 1: PRESENTATION                                       │
│  Google AppSheet (iOS / Android)                            │
│  Search · Filter · Detail · Add/Edit · Camera · Offline     │
└───────────────────────────┬─────────────────────────────────┘
                            │  real-time sync
                            ▼
┌─────────────────────────────────────────────────────────────┐
│  TIER 2: DATABASE ENGINE                                    │
│  Microsoft Excel: structured relational tables              │
└───────────────────────────┬─────────────────────────────────┘
                            │  Image reference
                            ▼
┌─────────────────────────────────────────────────────────────┐
│  TIER 3: ASSET STORAGE                                      │
│  Google Drive: indexed component image repository           │
└─────────────────────────────────────────────────────────────┘
```

---

## 🗄️ Data Schema

A single, flat, well-typed table keeps the data model simple to maintain and fast to query.

```
┌────────────────────────────────────────────────────────────────┐
│                     SPARE_PARTS (table)                        │
├──────────────────────┬───────────────┬─────────────────────────┤
│ Field                │ Type          │ Description             │
├──────────────────────┼───────────────┼─────────────────────────┤
│ 🔑 Item_Code  (req.) │ Text (PK)     │ Unique part identifier  │
│ Part_Name_EN         │ Text          │ English component name  │
│ Part_Name_AR         │ Text          │ Arabic component name   │
│ Part_Description_EN  │ Text          │ Technical description / │
│                      │               │ manufacturer part no.   │
│ Category_Type        │ Enum          │ Sensors | Pneumatics |  │
│                      │               │ Temp. Controllers |     │
│                      │               │ Valves | Motors |       │
│                      │               │ PLC Modules             │
│ Source_File_Page     │ Text          │ Origin catalog file/page│
│ Image        (req.)  │ Image         │ ──▶ Google Drive file   │
└──────────────────────┴───────────────┴─────────────────────────┘
```

> ℹ️ Field names reflect the real schema. All **values** shown in this repository are sanitized placeholders (see [Confidentiality Disclaimer](#-confidentiality-disclaimer)).

---

## 🧠 Key Engineering Decisions

### 1. Offline-First Capability
Factory production halls are often **network dead zones**. Rather than assuming connectivity, I configured **offline data caching** so part details and reference photos remain available without a signal. Changes sync when the connection returns. A catalog that fails exactly where it is needed is worse than none, so reliability on the shop floor was the top priority.

### 2. Standardized Naming Taxonomy
Search is only as good as the data behind it. I defined a **consistent naming convention and a fixed category taxonomy** (Sensors, Pneumatics, Temperature Controllers, Valves, Motors, PLC Modules) so that:
- the same component is never listed under multiple names,
- filtering by subsystem is predictable and complete,
- new entries added from the field stay consistent over time.

### 3. Bilingual Data Model (EN / AR)
Technicians work in both Arabic and English. Separate English and Arabic name fields, plus bilingual field labels throughout the UI, make the tool usable by the whole crew and make searches succeed in either language.

### 4. Visual Verification as an Error-Prevention Control
Text descriptions alone can look identical across similar parts. Attaching a **reference photo to every entry** (captured directly through the in-app camera) adds a second, visual check that targets wrong-part selection.

### 5. Traceability & Data Quality by Design
A **Source (File / Page)** field links each entry back to its manufacturer documentation, and **mandatory Item Code and Image fields** block incomplete records at the point of entry.

### 6. Right-Sized Tooling (Low-Code, 3-Tier Separation)
I chose **AppSheet + Excel + Google Drive** deliberately: fast to deploy within a 2-month window, cross-platform, and **maintainable by plant staff without specialized development skills**. Separating UI, data, and asset storage keeps each layer independently replaceable. If the plant later adopts a full CMMS or ERP, the structured schema can migrate cleanly.

### 7. Controlled Field Data Entry
Add, edit, and delete actions are available to **authorized engineers and technicians**, balancing the speed of in-the-field updates against data quality and governance.

---

## 📈 Operational Impact

The core operational metric targeted is **Mean Time to Identify (MTTI)**: the time from "a part is needed" to "the correct part is confirmed."

| Before | After |
|---|---|
| Searching manual logs and scattered records | Single searchable mobile catalog |
| Specs and models in different places | Unified record: description + category + source + photo |
| No visual confirmation, risk of wrong part | Reference photo on every item |
| Dependent on connectivity or desk access | Offline-capable, on the shop floor |
| English-only or paper-based references | Bilingual EN/AR records |
| Knowledge held by individuals | Shared, continuously growing team resource |

**Outcomes:**
- ⏱️ **Reduced MTTI** through sub-5-second search and filtering during breakdowns and PM shifts
- 🛡️ **Fewer identification and installation errors** through visual verification
- 🔄 **A living catalog** that grows as technicians add and correct parts directly from the field
- 🏭 **A step toward industrial digitalization**: a practical, low-cost digital tool adopted at the point of work

---

## 🛠️ Skills Demonstrated

`Industrial Digitalization` · `Maintenance Engineering` · `Mobile App Development (No-Code)` · `Relational Data Modeling` · `Systems Architecture` · `Bilingual UX for Industrial Environments` · `Offline-First Design` · `Data Validation & Traceability` · `Independent Project Delivery`

---

## 🔒 Confidentiality Disclaimer

This repository is public. **All records, part names, item codes, descriptions, and images shown in the screenshots and examples use sanitized or placeholder data, and identifying codes have been redacted.** No real ERP codes, internal inventory quantities, prices, or sensitive company warehouse information are included. This case study documents the **engineering approach and system design only**.

---

<div align="center">

**Ahmed M. Saafan** · Mechatronics Engineer · 
## 📩 Contact

📧 **Email:** Ahmed.saafan.eng@gmail.com  
🔗 **LinkedIn:** [Ahmed M. Saafan](https://www.linkedin.com/in/ahmed-saafan-a37401320)
[⬆ Back to top](#-industrial-spare-parts-catalog--lookup-system)

</div>
