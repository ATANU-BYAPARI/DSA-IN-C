const express = require('express');
const mongoose = require('mongoose');
const multer = require('multer');
const path = require('path');
const cors = require('cors');

const app = express();
const port = 3000;

// Middleware
app.use(cors());
app.use(express.json());

// Configure multer for file uploads
const storage = multer.diskStorage({
    destination: (req, file, cb) => {
        cb(null, 'uploads/');
    },
    filename: (req, file, cb) => {
        cb(null, Date.now() + path.extname(file.originalname));
    }
});
const upload = multer({ storage });

// MongoDB Connection
mongoose.connect('mongodb://localhost:27017/propertyDB', {
    useNewUrlParser: true,
    useUnifiedTopology: true
}).then(() => console.log('Connected to MongoDB'))
  .catch(err => console.error('MongoDB connection error:', err));

// MongoDB Schema
const propertySchema = new mongoose.Schema({
    name: { type: String, required: true },
    oneLineBio: { type: String, required: true },
    type: { type: String, required: true },
    bhk: { type: String },
    foodIncluded: { type: String },
    meals: { type: [String] },
    roomsAvailable: { type: [String] },
    suitableFor: { type: String, required: true },
    outerImage: { type: String, required: true },
    innerImage: { type: String, required: true },
    moreImages: { type: [String], required: true },
    foodMenuImage: { type: String },
    facilities: [{
        name: String,
        distance: Number
    }],
    address: {
        area: { type: String, required: true },
        district: { type: String, required: true },
        city: { type: String, required: true },
        pin: { type: String, required: true },
        landmark: { type: String },
        locationLink: { type: String }
    },
    rentDetails: {
        monthlyRent: { type: Number, required: true }
    },
    owner: { type: String, required: true },
    bio: { type: String, required: true },
    features: { type: [String], required: true },
    contact: {
        phone: { type: String, required: true },
        email: { type: String, required: true }
    },
    planPurchased: { type: Boolean, required: true },
    createdAt: { type: Date, default: Date.now }
});

const Property = mongoose.model('Property', propertySchema);

// API Endpoint to Handle Form Submission
app.post('/api/properties', upload.fields([
    { name: 'outerImage', maxCount: 1 },
    { name: 'innerImage', maxCount: 1 },
    { name: 'moreImages', maxCount: 10 },
    { name: 'foodMenuImage', maxCount: 1 }
]), async (req, res) => {
    try {
        const { name, oneLineBio, type, bhk, foodIncluded, meals, roomsAvailable, suitableFor, facilities,
                address, rentDetails, owner, bio, features, contact, planPurchased } = req.body;

        // Parse JSON strings
        const parsedMeals = meals ? JSON.parse(meals) : [];
        const parsedRoomsAvailable = roomsAvailable ? JSON.parse(roomsAvailable) : [];
        const parsedFacilities = facilities ? Object.keys(facilities).map(key => ({
            name: facilities[key].name,
            distance: parseFloat(facilities[key].distance)
        })) : [];
        const parsedAddress = address ? {
            area: address.area,
            district: address.district,
            city: address.city,
            pin: address.pin,
            landmark: address.landmark,
            locationLink: address.locationLink
        } : {};
        const parsedRentDetails = rentDetails ? { monthlyRent: parseFloat(rentDetails.monthlyRent) } : {};
        const parsedFeatures = features ? JSON.parse(features) : [];
        const parsedContact = contact ? { phone: contact.phone, email: contact.email } : {};

        // Handle file uploads
        const outerImage = req.files['outerImage'] ? req.files['outerImage'][0].path : null;
        const innerImage = req.files['innerImage'] ? req.files['innerImage'][0].path : null;
        const moreImages = req.files['moreImages'] ? req.files['moreImages'].map(file => file.path) : [];
        const foodMenuImage = req.files['foodMenuImage'] ? req.files['foodMenuImage'][0].path : null;

        // Create new property document
        const property = new Property({
            name,
            oneLineBio,
            type,
            bhk,
            foodIncluded,
            meals: parsedMeals,
            roomsAvailable: parsedRoomsAvailable,
            suitableFor,
            outerImage,
            innerImage,
            moreImages,
            foodMenuImage,
            facilities: parsedFacilities,
            address: parsedAddress,
            rentDetails: parsedRentDetails,
            owner,
            bio,
            features: parsedFeatures,
            contact: parsedContact,
            planPurchased: planPurchased === 'true'
        });

        // Save to MongoDB
        await property.save();
        res.status(201).json({ message: 'Property listing created successfully', property });
    } catch (error) {
        console.error('Error saving property:', error);
        res.status(500).json({ error: 'Failed to save property listing' });
    }
});

// Start Server
app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
