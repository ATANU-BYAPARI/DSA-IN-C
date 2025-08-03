function goBack() {
    window.history.back();
}

document.addEventListener('DOMContentLoaded', () => {
    const form = document.getElementById('form');
    const submitBtn = document.getElementById('submitBtn');
    const choosePlanBtn = document.getElementById('choosePlanBtn');
    const planStatus = document.getElementById('planStatus');
    let planPurchased = false;

    // --- Helper Functions for Validation ---
    const showError = (input, message) => {
        const formGroup = input.parentElement;
        const errorDiv = formGroup.querySelector('.error-message');
        if (errorDiv) {
            errorDiv.textContent = message;
            input.classList.add('invalid');
        }
    };

    const clearError = (input) => {
        const formGroup = input.parentElement;
        const errorDiv = formGroup.querySelector('.error-message');
        if (errorDiv) {
            errorDiv.textContent = '';
            input.classList.remove('invalid');
        }
    };

    // --- Plan Selection Simulation ---
    choosePlanBtn.addEventListener('click', () => {
        planPurchased = true;
        planStatus.textContent = 'Done';
        planStatus.classList.remove('pending');
        planStatus.classList.add('done');
        choosePlanBtn.disabled = true;
        choosePlanBtn.style.opacity = '0.6';
        choosePlanBtn.style.cursor = 'not-allowed';
    });

    // --- Property Type and Conditional Fields ---
    const type = document.getElementById('type');
    const bhkDiv = document.getElementById('bhkDiv');
    const foodIncludedDiv = document.getElementById('foodIncludedDiv');
    const foodIncluded = document.getElementById('foodIncluded');
    const mealOptions = document.getElementById('mealOptions');
    const roomsAvailableDiv = document.getElementById('roomsAvailableDiv');

    type.addEventListener('change', () => {
        bhkDiv.classList.toggle('hidden', type.value !== 'House');
        foodIncludedDiv.classList.toggle('hidden', !['PG', 'Mess', 'Hostel'].includes(type.value));
        roomsAvailableDiv.classList.toggle('hidden', !['PG', 'Mess', 'Hostel'].includes(type.value));
        foodIncluded.required = ['PG', 'Mess', 'Hostel'].includes(type.value);
        mealOptions.classList.add('hidden');
        if (foodIncludedDiv.classList.contains('hidden')) {
            foodIncluded.value = '';
            const mealCheckboxes = mealOptions.querySelectorAll('input[name="meals"]');
            mealCheckboxes.forEach(cb => {
                cb.checked = false;
                cb.required = false;
            });
            const roomsCheckboxes = roomsAvailableDiv.querySelectorAll('input[name="roomsAvailable"]');
            roomsCheckboxes.forEach(cb => {
                cb.checked = false;
                cb.required = false;
            });
        } else {
            const roomsCheckboxes = roomsAvailableDiv.querySelectorAll('input[name="roomsAvailable"]');
            roomsCheckboxes.forEach(cb => cb.required = true);
        }
    });

    foodIncluded.addEventListener('change', () => {
        mealOptions.classList.toggle('hidden', foodIncluded.value !== 'Yes');
        const mealCheckboxes = mealOptions.querySelectorAll('input[name="meals"]');
        mealCheckboxes.forEach(cb => cb.required = foodIncluded.value === 'Yes');
    });

    // --- Image Upload Handlers ---
    const outerImageInput = document.getElementById('outerImage');
    const innerImageInput = document.getElementById('innerImage');
    const moreImagesInput = document.getElementById('moreImages');
    const foodMenuImageInput = document.getElementById('foodMenuImage');
    const imagePreviewOuter = document.getElementById('imagePreviewOuter');
    const imagePreviewInner = document.getElementById('imagePreviewInner');
    const imagePreviewMore = document.getElementById('imagePreviewMore');
    const imagePreviewFoodMenu = document.getElementById('imagePreviewFoodMenu');
    const moreImagesError = document.getElementById('moreImagesError');

    let outerFile, innerFile, foodMenuFile, moreFiles = new DataTransfer();

    function createImagePreview(input, previewContainer, file, index = null) {
        const reader = new FileReader();
        reader.onload = () => {
            const previewContainerDiv = document.createElement('div');
            previewContainerDiv.className = 'img-preview-container';
            const img = document.createElement('img');
            img.src = reader.result;
            img.className = 'preview-img';
            const removeBtn = document.createElement('button');
            removeBtn.type = 'button';
            removeBtn.className = 'remove-img-btn';
            removeBtn.innerHTML = '×';
            removeBtn.addEventListener('click', () => {
                if (input === moreImagesInput) {
                    const newFiles = new DataTransfer();
                    for (let i = 0; i < moreFiles.files.length; i++) {
                        if (i !== index) newFiles.items.add(moreFiles.files[i]);
                    }
                    moreFiles = newFiles;
                    moreImagesInput.files = moreFiles.files;
                    updateMoreImagesPreview();
                } else {
                    input.value = '';
                    previewContainer.innerHTML = '';
                }
            });
            previewContainerDiv.append(img, removeBtn);
            if (input !== moreImagesInput) {
                previewContainer.innerHTML = '';
            }
            previewContainer.appendChild(previewContainerDiv);
        };
        reader.readAsDataURL(file);
    }

    outerImageInput.addEventListener('change', (e) => {
        if (e.target.files[0]) {
            outerFile = e.target.files[0];
            createImagePreview(outerImageInput, imagePreviewOuter, outerFile);
        }
    });

    innerImageInput.addEventListener('change', (e) => {
        if (e.target.files[0]) {
            innerFile = e.target.files[0];
            createImagePreview(innerImageInput, imagePreviewInner, innerFile);
        }
    });

    moreImagesInput.addEventListener('change', (e) => {
        for (const file of e.target.files) {
            moreFiles.items.add(file);
        }
        moreImagesInput.files = moreFiles.files;
        updateMoreImagesPreview();
    });

    foodMenuImageInput.addEventListener('change', (e) => {
        if (e.target.files[0]) {
            foodMenuFile = e.target.files[0];
            createImagePreview(foodMenuImageInput, imagePreviewFoodMenu, foodMenuFile);
        }
    });

    function updateMoreImagesPreview() {
        imagePreviewMore.innerHTML = '';
        moreImagesError.textContent = '';
        for (let i = 0; i < moreFiles.files.length; i++) {
            createImagePreview(moreImagesInput, imagePreviewMore, moreFiles.files[i], i);
        }
    }

    // --- Bio Character Counter ---
    const bio = document.getElementById('bio');
    const charCounter = document.getElementById('charCounter');
    bio.addEventListener('input', () => {
        const remaining = 500 - bio.value.length;
        charCounter.textContent = `${remaining} characters remaining`;
    });

    // --- One-Line Bio Character Counter ---
    const oneLineBio = document.getElementById('oneLineBio');
    const oneLineBioCounter = document.getElementById('oneLineBioCounter');
    oneLineBio.addEventListener('input', () => {
        const used = oneLineBio.value.length;
        oneLineBioCounter.textContent = `${used}/40`;
    });

    // --- Form Validation and Submission Logic ---
    form.addEventListener('submit', async (e) => {
        e.preventDefault();
        let isValid = true;

        // Clear all previous errors
        document.querySelectorAll('.error-message').forEach(div => div.textContent = '');
        document.querySelectorAll('input, select, textarea').forEach(el => el.classList.remove('invalid'));

        // 1. Validate required fields
        form.querySelectorAll('input[required], select[required], textarea[required]').forEach(input => {
            if (!input.value.trim()) {
                showError(input, 'This field is required.');
                isValid = false;
            } else if (input.pattern && !input.checkValidity()) {
                showError(input, `Please match the format: ${input.placeholder || 'Invalid format'}`);
                isValid = false;
            } else {
                clearError(input);
            }
        });

        // 2. Validate Meal Options for PG/Mess/Hostel
        if (['PG', 'Mess', 'Hostel'].includes(type.value) && foodIncluded.value === 'Yes') {
            const meals = document.querySelectorAll('#mealOptions input[name="meals"]:checked');
            if (meals.length === 0) {
                mealOptions.querySelector('.error-message').textContent = 'Please select at least one meal option.';
                isValid = false;
            }
        }

        // 3. Validate Rooms Available for PG/Mess/Hostel
        if (['PG', 'Mess', 'Hostel'].includes(type.value)) {
            const rooms = document.querySelectorAll('#roomsAvailableDiv input[name="roomsAvailable"]:checked');
            if (rooms.length === 0) {
                roomsAvailableDiv.querySelector('.error-message').textContent = 'Please select at least one room option.';
                isValid = false;
            }
        }

        // 4. Validate Image Uploads
        if (!outerImageInput.files[0]) {
            showError(outerImageInput, 'Please upload an outer view image.');
            isValid = false;
        }
        if (!innerImageInput.files[0]) {
            showError(innerImageInput, 'Please upload an inner view image.');
            isValid = false;
        }
        if (moreFiles.files.length < 2) {
            moreImagesError.textContent = 'Please upload at least 2 additional images.';
            moreImagesInput.classList.add('invalid');
            isValid = false;
        }

        // 5. Validate Features Checkboxes
        const features = document.querySelectorAll('#features input:checked');
        const featureError = document.getElementById('featureError');
        if (features.length < 3) {
            featureError.textContent = 'Please select at least 3 features.';
            isValid = false;
        }

        // 6. Validate Plan Purchase
        const planError = document.getElementById('planError');
        if (!planPurchased) {
            planError.textContent = 'Please choose a subscription plan to continue.';
            isValid = false;
        }

        // 7. Validate Nearby Facilities (optional, but if provided, ensure valid)
        const facilities = [
            { name: document.getElementById('facility1'), distance: document.getElementById('facility1Distance') },
            { name: document.getElementById('facility2'), distance: document.getElementById('facility2Distance') },
            { name: document.getElementById('facility3'), distance: document.getElementById('facility3Distance') }
        ];
        facilities.forEach(facility => {
            if (facility.name.value.trim() && !facility.distance.value.trim()) {
                showError(facility.distance, 'Please provide a distance for the facility.');
                isValid = false;
            } else if (!facility.name.value.trim() && facility.distance.value.trim()) {
                showError(facility.name, 'Please provide a facility name for the distance.');
                isValid = false;
            } else {
                clearError(facility.name);
                clearError(facility.distance);
            }
        });

        // 8. Validate Location Link (optional, but if provided, ensure valid URL)
        const locationLink = document.getElementById('locationLink');
        if (locationLink.value.trim() && !/^(https?:\/\/)/i.test(locationLink.value.trim())) {
            showError(locationLink, 'Please enter a valid URL (e.g., https://...).');
            isValid = false;
        } else {
            clearError(locationLink);
        }

        if (isValid) {
            submitBtn.disabled = true;
            submitBtn.textContent = 'Submitting...';

            // Collect form data
            const formData = new FormData();
            formData.append('name', document.getElementById('name').value);
            formData.append('oneLineBio', document.getElementById('oneLineBio').value);
            formData.append('type', type.value);
            if (type.value === 'House') {
                formData.append('bhk', document.getElementById('bhk').value);
            }
            if (['PG', 'Mess', 'Hostel'].includes(type.value)) {
                formData.append('foodIncluded', foodIncluded.value);
                if (foodIncluded.value === 'Yes') {
                    const meals = Array.from(document.querySelectorAll('#mealOptions input[name="meals"]:checked')).map(cb => cb.value);
                    formData.append('meals', JSON.stringify(meals));
                }
                const rooms = Array.from(document.querySelectorAll('#roomsAvailableDiv input[name="roomsAvailable"]:checked')).map(cb => cb.value);
                formData.append('roomsAvailable', JSON.stringify(rooms));
            }
            formData.append('suitableFor', document.getElementById('suitableFor').value);
            formData.append('outerImage', outerImageInput.files[0]);
            formData.append('innerImage', innerImageInput.files[0]);
            for (const file of moreFiles.files) {
                formData.append('moreImages', file);
            }
            if (foodMenuImageInput.files[0]) {
                formData.append('foodMenuImage', foodMenuImageInput.files[0]);
            }
            facilities.forEach((facility, index) => {
                if (facility.name.value.trim() && facility.distance.value.trim()) {
                    formData.append(`facilities[${index}][name]`, facility.name.value);
                    formData.append(`facilities[${index}][distance]`, facility.distance.value);
                }
            });
            formData.append('address[area]', document.getElementById('area').value);
            formData.append('address[district]', document.getElementById('district').value);
            formData.append('address[city]', document.getElementById('city').value);
            formData.append('address[pin]', document.getElementById('pin').value);
            if (document.getElementById('landmark').value.trim()) {
                formData.append('address[landmark]', document.getElementById('landmark').value);
            }
            if (locationLink.value.trim()) {
                formData.append('address[locationLink]', locationLink.value);
            }
            formData.append('rentDetails[monthlyRent]', document.getElementById('monthlyRent').value);
            formData.append('owner', document.getElementById('owner').value);
            formData.append('bio', bio.value);
            const selectedFeatures = Array.from(features).map(cb => cb.value);
            formData.append('features', JSON.stringify(selectedFeatures));
            formData.append('contact[phone]', document.getElementById('contact_phone').value);
            formData.append('contact[email]', document.getElementById('contact_email').value);
            formData.append('planPurchased', planPurchased);

            try {
                const response = await fetch('/api/properties', {
                    method: 'POST',
                    body: formData
                });

                if (!response.ok) {
                    throw new Error('Failed to submit property listing');
                }

                const result = await response.json();
                console.log('Property listing submitted:', result);

                alert('Property listing submitted successfully!');
                form.reset();
                submitBtn.disabled = false;
                submitBtn.textContent = 'Submit Listing';
                imagePreviewOuter.innerHTML = '';
                imagePreviewInner.innerHTML = '';
                imagePreviewMore.innerHTML = '';
                imagePreviewFoodMenu.innerHTML = '';
                moreFiles = new DataTransfer();
                moreImagesInput.files = moreFiles.files;
                foodMenuImageInput.value = '';
                charCounter.textContent = '500 characters remaining';
                oneLineBioCounter.textContent = '0/40';
                bhkDiv.classList.add('hidden');
                foodIncludedDiv.classList.add('hidden');
                mealOptions.classList.add('hidden');
                roomsAvailableDiv.classList.add('hidden');
                planPurchased = false;
                planStatus.textContent = 'Pending';
                planStatus.classList.remove('done');
                planStatus.classList.add('pending');
                choosePlanBtn.disabled = false;
                choosePlanBtn.style.opacity = '1';
                choosePlanBtn.style.cursor = 'pointer';
            } catch (error) {
                console.error('Error submitting form:', error);
                alert('Failed to submit property listing. Please try again.');
                submitBtn.disabled = false;
                submitBtn.textContent = 'Submit Listing';
            }
        } else {
            const firstError = form.querySelector('.invalid') || planError || roomsAvailableDiv.querySelector('.error-message');
            if (firstError) {
                firstError.focus();
            }
        }
    });
});
